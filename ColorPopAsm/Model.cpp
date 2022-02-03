#include "Model.h"

Model::~Model() {
	delete[] inputBuffer;
	delete[] outputBuffer;
	delete cutoffLow;
	delete cutoffHigh;
}

void Model::debug(const string& msg, const string& prefix) {
#ifdef DEBUG
	cout << prefix << " " << msg << endl;
#endif
}

bool Model::error(const string& msg) {
	debug(msg, "!!");
	throw std::runtime_error(msg);
	return true;
}

bool Model::read() {
	std::ifstream inFile(inFilePath, std::ios::binary);

	if (!inFile) {
		char actualPath[300];
		GetFullPathNameA(inFilePath, 300, actualPath, NULL);
		string errMsg = "can't open file for read: ";
		errMsg += actualPath;
		return error(errMsg);
	}

	inFile.seekg(0, std::ios::end);
	fileSize = inFile.tellg();
	inFile.seekg(0, std::ios::beg);

	if (fileSize < sizeof(myBITMAPFILEHEADER))
		return error("input file is not a bitmap");

	delete[] inputBuffer;
	inputBuffer = new uchar[fileSize]();
	inFile.read(reinterpret_cast<char*>(inputBuffer), fileSize);
	inFile.close();

	fileHeader = (myPBITMAPFILEHEADER)(inputBuffer);
	infoHeader = (myPBITMAPINFOHEADER)(inputBuffer + sizeof(myBITMAPFILEHEADER));

	if (inputBuffer[0] != 'B' || inputBuffer[1] != 'M')
		return error("input file is not a bitmap");

	rows = infoHeader->biHeight;
	cols = infoHeader->biWidth;
	endOffset = cols % 4;

	delete[] outputBuffer;
	outputBuffer = new uchar[fileSize]();
	std::copy( // copy header
		inputBuffer,
		inputBuffer + fileHeader->bfOffBits,
		outputBuffer
	);

	debug("file read");
	return false;
}

bool Model::write() {
	if (!outFilePath)
		return false;

	std::ofstream outFile(outFilePath, std::ios::binary);
	if (!outFile) {
		char actualPath[300];
		GetFullPathNameA(outFilePath, 300, actualPath, NULL);
		string errMsg = "can't open file for write: ";
		errMsg += actualPath;
		return error(errMsg);
	}

	outFile.write(reinterpret_cast<char*>(outputBuffer), fileSize);
	outFile.close();
	debug("file written");
	return false;
}

int Model::rowEndIdx(const uint y) const {
	return fileSize - (rows - y) * endOffset - 3 * y * cols - 3;
}

void Model::thread(std::atomic<uint>& gy, void(Model::*imp)(const uchar*, uchar* output, const int, const int, myRGB*, myRGB*)) {
	uint y;
	while ((y = gy++) < rows) {
		int rei = rowEndIdx(y);
		(this->*imp)(inputBuffer, outputBuffer, rei, cols, cutoffLow, cutoffHigh);
	}
}

void Model::cppRow(const uchar* input, uchar* output, const int rei, const int cols, myRGB* cutoffLow, myRGB* cutoffHigh) {
	for (int x = 0; x < cols; x++)
		cppProc(input, output, rei, x, cutoffLow, cutoffHigh);
}

void Model::asmRow(const uchar* input, uchar* output, const int rei, const int cols, myRGB* cutoffLow, myRGB* cutoffHigh) {
	for (int x = cols - 1; x >= 0; x -= 16)
		asmProc(input, output, rei, x, cutoffLow, cutoffHigh);
}

void Model::runThreads(const uint concurrent, const bool useAsm) {
	std::vector<std::thread> threads;
	std::atomic<uint> gy = 0;

	auto implementation = useAsm ? &Model::asmRow : &Model::cppRow;
	for (uint i = 0; i < concurrent; i++)
		threads.emplace_back(&Model::thread, this, std::ref(gy), implementation);

	for (auto& t : threads)
		if (t.joinable())
			t.join();
}

uint Model::benchmark(const uint n, const uint concurrent, const bool useAsm) {
	auto t0 = std::chrono::high_resolution_clock::now();

	for (uint i = 0; i < n; i++)
		runThreads(concurrent, useAsm);

	auto t1 = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();
}

uint Model::run(const uint n, const uint concurrent, const bool useAsm) {
	if (!inputBuffer) { // run only when needed
		bool errorReading = read();
		if (errorReading)
			return 0;
	}

	// cout << fileHeader->bfSize / 1024 / 1024 << "MB " << infoHeader->biWidth << "x" << infoHeader->biHeight << endl;

	uint durationMs = benchmark(n, concurrent, useAsm);

	debug("ms", std::to_string(durationMs));

	return durationMs;
}