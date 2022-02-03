#pragma once

#include "Model.h"
#include "unmanaged.h"

namespace ColorPopAsm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UI
	/// </summary>
	public ref class UI : public System::Windows::Forms::Form
	{
	public:
		UI(void)
		{
			InitializeComponent();
			setThreadsAuto();
			setSettings();
			setImage1();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RadioButton^ selectCpp;
	private: System::Windows::Forms::RadioButton^ selectAsm;
	protected:

	protected:

	private: System::Windows::Forms::TrackBar^ threadsSlider;
	private: System::Windows::Forms::Label^ threadsLabel;
	private: System::Windows::Forms::Button^ runButton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ infoBox;
	private: System::Windows::Forms::RadioButton^ largeImage;
	private: System::Windows::Forms::RadioButton^ mediumImage;
	private: System::Windows::Forms::RadioButton^ smallImage;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ runx10button;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ labelResolution;
	private: System::Windows::Forms::Label^ labelSize;
	private: System::Windows::Forms::Button^ otherButton;
	private: System::Windows::Forms::TrackBar^ sliderR;
	private: System::Windows::Forms::Label^ labelR;
	private: System::Windows::Forms::Label^ labelR2;
	private: System::Windows::Forms::Label^ labelG2;

	private: System::Windows::Forms::Label^ labelG;
	private: System::Windows::Forms::TrackBar^ sliderG;

	private: System::Windows::Forms::Label^ labelB2;

	private: System::Windows::Forms::Label^ labelB;
	private: System::Windows::Forms::TrackBar^ sliderB;


	private: System::Windows::Forms::Label^ labelTolerance2;

	private: System::Windows::Forms::Label^ labelTolerance;
	private: System::Windows::Forms::TrackBar^ sliderTolerance;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->selectCpp = (gcnew System::Windows::Forms::RadioButton());
			this->selectAsm = (gcnew System::Windows::Forms::RadioButton());
			this->threadsSlider = (gcnew System::Windows::Forms::TrackBar());
			this->threadsLabel = (gcnew System::Windows::Forms::Label());
			this->runButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->infoBox = (gcnew System::Windows::Forms::TextBox());
			this->largeImage = (gcnew System::Windows::Forms::RadioButton());
			this->mediumImage = (gcnew System::Windows::Forms::RadioButton());
			this->smallImage = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->otherButton = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->runx10button = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->labelResolution = (gcnew System::Windows::Forms::Label());
			this->labelSize = (gcnew System::Windows::Forms::Label());
			this->sliderR = (gcnew System::Windows::Forms::TrackBar());
			this->labelR = (gcnew System::Windows::Forms::Label());
			this->labelR2 = (gcnew System::Windows::Forms::Label());
			this->labelG2 = (gcnew System::Windows::Forms::Label());
			this->labelG = (gcnew System::Windows::Forms::Label());
			this->sliderG = (gcnew System::Windows::Forms::TrackBar());
			this->labelB2 = (gcnew System::Windows::Forms::Label());
			this->labelB = (gcnew System::Windows::Forms::Label());
			this->sliderB = (gcnew System::Windows::Forms::TrackBar());
			this->labelTolerance2 = (gcnew System::Windows::Forms::Label());
			this->labelTolerance = (gcnew System::Windows::Forms::Label());
			this->sliderTolerance = (gcnew System::Windows::Forms::TrackBar());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadsSlider))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderB))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderTolerance))->BeginInit();
			this->SuspendLayout();
			// 
			// selectCpp
			// 
			this->selectCpp->AutoSize = true;
			this->selectCpp->Location = System::Drawing::Point(6, 19);
			this->selectCpp->Name = L"selectCpp";
			this->selectCpp->Size = System::Drawing::Size(44, 17);
			this->selectCpp->TabIndex = 0;
			this->selectCpp->Text = L"C++";
			this->selectCpp->UseVisualStyleBackColor = true;
			// 
			// selectAsm
			// 
			this->selectAsm->AutoSize = true;
			this->selectAsm->Checked = true;
			this->selectAsm->Location = System::Drawing::Point(6, 42);
			this->selectAsm->Name = L"selectAsm";
			this->selectAsm->Size = System::Drawing::Size(69, 17);
			this->selectAsm->TabIndex = 1;
			this->selectAsm->TabStop = true;
			this->selectAsm->Text = L"Assembly";
			this->selectAsm->UseVisualStyleBackColor = true;
			// 
			// threadsSlider
			// 
			this->threadsSlider->Location = System::Drawing::Point(57, 15);
			this->threadsSlider->Maximum = 64;
			this->threadsSlider->Minimum = 1;
			this->threadsSlider->Name = L"threadsSlider";
			this->threadsSlider->Size = System::Drawing::Size(446, 45);
			this->threadsSlider->TabIndex = 2;
			this->threadsSlider->Value = 8;
			this->threadsSlider->Scroll += gcnew System::EventHandler(this, &UI::threadsSlider_Scroll);
			// 
			// threadsLabel
			// 
			this->threadsLabel->AutoSize = true;
			this->threadsLabel->Location = System::Drawing::Point(21, 25);
			this->threadsLabel->Name = L"threadsLabel";
			this->threadsLabel->Size = System::Drawing::Size(13, 13);
			this->threadsLabel->TabIndex = 3;
			this->threadsLabel->Text = L"8";
			// 
			// runButton
			// 
			this->runButton->Location = System::Drawing::Point(643, 153);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(75, 23);
			this->runButton->TabIndex = 4;
			this->runButton->Text = L"run";
			this->runButton->UseVisualStyleBackColor = true;
			this->runButton->Click += gcnew System::EventHandler(this, &UI::runButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(42, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"threads";
			// 
			// infoBox
			// 
			this->infoBox->Location = System::Drawing::Point(521, 201);
			this->infoBox->Name = L"infoBox";
			this->infoBox->ReadOnly = true;
			this->infoBox->Size = System::Drawing::Size(197, 20);
			this->infoBox->TabIndex = 6;
			// 
			// largeImage
			// 
			this->largeImage->AutoSize = true;
			this->largeImage->Location = System::Drawing::Point(6, 19);
			this->largeImage->Name = L"largeImage";
			this->largeImage->Size = System::Drawing::Size(48, 17);
			this->largeImage->TabIndex = 7;
			this->largeImage->Text = L"large";
			this->largeImage->UseVisualStyleBackColor = true;
			this->largeImage->CheckedChanged += gcnew System::EventHandler(this, &UI::largeImage_CheckedChanged);
			// 
			// mediumImage
			// 
			this->mediumImage->AutoSize = true;
			this->mediumImage->Location = System::Drawing::Point(6, 42);
			this->mediumImage->Name = L"mediumImage";
			this->mediumImage->Size = System::Drawing::Size(61, 17);
			this->mediumImage->TabIndex = 8;
			this->mediumImage->Text = L"medium";
			this->mediumImage->UseVisualStyleBackColor = true;
			this->mediumImage->CheckedChanged += gcnew System::EventHandler(this, &UI::mediumImage_CheckedChanged);
			// 
			// smallImage
			// 
			this->smallImage->AutoSize = true;
			this->smallImage->Checked = true;
			this->smallImage->Location = System::Drawing::Point(6, 65);
			this->smallImage->Name = L"smallImage";
			this->smallImage->Size = System::Drawing::Size(48, 17);
			this->smallImage->TabIndex = 9;
			this->smallImage->TabStop = true;
			this->smallImage->Text = L"small";
			this->smallImage->UseVisualStyleBackColor = true;
			this->smallImage->CheckedChanged += gcnew System::EventHandler(this, &UI::smallImage_CheckedChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->otherButton);
			this->groupBox1->Controls->Add(this->largeImage);
			this->groupBox1->Controls->Add(this->smallImage);
			this->groupBox1->Controls->Add(this->mediumImage);
			this->groupBox1->Location = System::Drawing::Point(521, 15);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(74, 114);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"image size";
			// 
			// otherButton
			// 
			this->otherButton->Location = System::Drawing::Point(6, 88);
			this->otherButton->Name = L"otherButton";
			this->otherButton->Size = System::Drawing::Size(62, 20);
			this->otherButton->TabIndex = 10;
			this->otherButton->Text = L"other";
			this->otherButton->UseVisualStyleBackColor = true;
			this->otherButton->Click += gcnew System::EventHandler(this, &UI::otherButton_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->selectCpp);
			this->groupBox2->Controls->Add(this->selectAsm);
			this->groupBox2->Location = System::Drawing::Point(622, 18);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(96, 65);
			this->groupBox2->TabIndex = 11;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"implementation";
			// 
			// runx10button
			// 
			this->runx10button->Location = System::Drawing::Point(643, 176);
			this->runx10button->Name = L"runx10button";
			this->runx10button->Size = System::Drawing::Size(75, 23);
			this->runx10button->TabIndex = 12;
#ifdef BENCHMARK
			this->runx10button->Text = L"benchmark";
#else
			this->runx10button->Text = L"run x10";
#endif
			this->runx10button->UseVisualStyleBackColor = true;
			this->runx10button->Click += gcnew System::EventHandler(this, &UI::runX10Button_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 242);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(350, 350);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(386, 242);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(350, 350);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 14;
			this->pictureBox2->TabStop = false;
			// 
			// labelResolution
			// 
			this->labelResolution->AutoSize = true;
			this->labelResolution->Location = System::Drawing::Point(524, 153);
			this->labelResolution->Name = L"labelResolution";
			this->labelResolution->Size = System::Drawing::Size(52, 13);
			this->labelResolution->TabIndex = 15;
			this->labelResolution->Text = L"resolution";
			// 
			// labelSize
			// 
			this->labelSize->AutoSize = true;
			this->labelSize->Location = System::Drawing::Point(524, 168);
			this->labelSize->Name = L"labelSize";
			this->labelSize->Size = System::Drawing::Size(25, 13);
			this->labelSize->TabIndex = 16;
			this->labelSize->Text = L"size";
			// 
			// sliderR
			// 
			this->sliderR->Location = System::Drawing::Point(57, 57);
			this->sliderR->Maximum = 255;
			this->sliderR->Name = L"sliderR";
			this->sliderR->Size = System::Drawing::Size(446, 45);
			this->sliderR->TabIndex = 17;
			this->sliderR->Scroll += gcnew System::EventHandler(this, &UI::sliderR_Scroll);
			// 
			// labelR
			// 
			this->labelR->AutoSize = true;
			this->labelR->Location = System::Drawing::Point(21, 57);
			this->labelR->Name = L"labelR";
			this->labelR->Size = System::Drawing::Size(15, 13);
			this->labelR->TabIndex = 18;
			this->labelR->Text = L"R";
			// 
			// labelR2
			// 
			this->labelR2->AutoSize = true;
			this->labelR2->Location = System::Drawing::Point(21, 70);
			this->labelR2->Name = L"labelR2";
			this->labelR2->Size = System::Drawing::Size(13, 13);
			this->labelR2->TabIndex = 19;
			this->labelR2->Text = L"0";
			this->labelR2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelG2
			// 
			this->labelG2->AutoSize = true;
			this->labelG2->Location = System::Drawing::Point(21, 110);
			this->labelG2->Name = L"labelG2";
			this->labelG2->Size = System::Drawing::Size(13, 13);
			this->labelG2->TabIndex = 22;
			this->labelG2->Text = L"0";
			this->labelG2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelG
			// 
			this->labelG->AutoSize = true;
			this->labelG->Location = System::Drawing::Point(21, 97);
			this->labelG->Name = L"labelG";
			this->labelG->Size = System::Drawing::Size(15, 13);
			this->labelG->TabIndex = 21;
			this->labelG->Text = L"G";
			// 
			// sliderG
			// 
			this->sliderG->Location = System::Drawing::Point(57, 97);
			this->sliderG->Maximum = 255;
			this->sliderG->Name = L"sliderG";
			this->sliderG->Size = System::Drawing::Size(446, 45);
			this->sliderG->TabIndex = 20;
			this->sliderG->Scroll += gcnew System::EventHandler(this, &UI::sliderG_Scroll);
			// 
			// labelB2
			// 
			this->labelB2->AutoSize = true;
			this->labelB2->Location = System::Drawing::Point(21, 153);
			this->labelB2->Name = L"labelB2";
			this->labelB2->Size = System::Drawing::Size(13, 13);
			this->labelB2->TabIndex = 25;
			this->labelB2->Text = L"0";
			this->labelB2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelB
			// 
			this->labelB->AutoSize = true;
			this->labelB->Location = System::Drawing::Point(21, 140);
			this->labelB->Name = L"labelB";
			this->labelB->Size = System::Drawing::Size(14, 13);
			this->labelB->TabIndex = 24;
			this->labelB->Text = L"B";
			// 
			// sliderB
			// 
			this->sliderB->Location = System::Drawing::Point(57, 140);
			this->sliderB->Maximum = 255;
			this->sliderB->Name = L"sliderB";
			this->sliderB->Size = System::Drawing::Size(446, 45);
			this->sliderB->TabIndex = 23;
			this->sliderB->Scroll += gcnew System::EventHandler(this, &UI::sliderB_Scroll);
			// 
			// labelTolerance2
			// 
			this->labelTolerance2->AutoSize = true;
			this->labelTolerance2->Location = System::Drawing::Point(21, 204);
			this->labelTolerance2->Name = L"labelTolerance2";
			this->labelTolerance2->Size = System::Drawing::Size(13, 13);
			this->labelTolerance2->TabIndex = 28;
			this->labelTolerance2->Text = L"1";
			this->labelTolerance2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelTolerance
			// 
			this->labelTolerance->AutoSize = true;
			this->labelTolerance->Location = System::Drawing::Point(7, 191);
			this->labelTolerance->Name = L"labelTolerance";
			this->labelTolerance->Size = System::Drawing::Size(51, 13);
			this->labelTolerance->TabIndex = 27;
			this->labelTolerance->Text = L"tolerance";
			// 
			// sliderTolerance
			// 
			this->sliderTolerance->Location = System::Drawing::Point(57, 191);
			this->sliderTolerance->Maximum = 255;
			this->sliderTolerance->Minimum = 1;
			this->sliderTolerance->Name = L"sliderTolerance";
			this->sliderTolerance->Size = System::Drawing::Size(446, 45);
			this->sliderTolerance->TabIndex = 26;
			this->sliderTolerance->Value = 1;
			this->sliderTolerance->Scroll += gcnew System::EventHandler(this, &UI::sliderTolerance_Scroll);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"bitmap|*.bmp";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &UI::openFileDialog1_FileOk);
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 607);
			this->Controls->Add(this->labelTolerance2);
			this->Controls->Add(this->labelTolerance);
			this->Controls->Add(this->sliderTolerance);
			this->Controls->Add(this->labelB2);
			this->Controls->Add(this->labelB);
			this->Controls->Add(this->sliderB);
			this->Controls->Add(this->labelG2);
			this->Controls->Add(this->labelG);
			this->Controls->Add(this->sliderG);
			this->Controls->Add(this->labelR2);
			this->Controls->Add(this->labelR);
			this->Controls->Add(this->sliderR);
			this->Controls->Add(this->labelSize);
			this->Controls->Add(this->labelResolution);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->runx10button);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->infoBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->runButton);
			this->Controls->Add(this->threadsLabel);
			this->Controls->Add(this->threadsSlider);
			this->Name = L"UI";
			this->Text = L"ColorPopAsm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->threadsSlider))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderB))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sliderTolerance))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		static HolderOfUnmanagedStuff* unmanaged = new HolderOfUnmanagedStuff();

		void updateThreadsLabel() {
			this->threadsLabel->Text = threadsSelected().ToString();
		}
		private: System::Void threadsSlider_Scroll(System::Object^ sender, System::EventArgs^ e) {
			updateThreadsLabel();
		}
		void setThreadsAuto() {
			uint threads = std::thread::hardware_concurrency();
			threads = min(this->threadsSlider->Maximum, threads);
			threads = max(this->threadsSlider->Minimum, threads);
			this->threadsSlider->Value = threads;
			updateThreadsLabel();
		}

		bool useAsmSelected() {
			return this->selectAsm->Checked;
		}
		unsigned threadsSelected() {
			return this->threadsSlider->Value;
		}
		void printInfo(String^ msg) {
			this->infoBox->Text = msg;
		}

		int getCurrentImageOption() {
			if (this->largeImage->Checked)
				return 0;
			else if (this->mediumImage->Checked)
				return 1;
			return 2;
		}

		String^ inputFilename;
		void setImage1() {
			this->runButton->Enabled = true;
			this->runx10button->Enabled = true;
			printInfo("");
			delete this->pictureBox1->Image;
			try {
				this->pictureBox1->Image = Image::FromFile(inputFilename);
				this->labelResolution->Text = this->pictureBox1->Image->Width.ToString() + " x " + this->pictureBox1->Image->Height.ToString();
				auto size = this->pictureBox1->Image->Width * this->pictureBox1->Image->Height * 3 / 1024 / 1024.0;
				this->labelSize->Text = size.ToString("0.0") +" MB";
			}
			catch (...) {
				MessageBox::Show("Can't open input file: " + inputFilename, "ERROR");
				printInfo("Please select valid file...");
				this->runButton->Enabled = false;
				this->runx10button->Enabled = false;
			}
		}
		void run(uint loopXTimes) {
			printInfo("Running..");
			Refresh();

			char inputFilenameCstr[300] = { 0 };
			if (inputFilename->Length >= sizeof(inputFilenameCstr)) {
				MessageBox::Show("file path too long", "ERROR");
				return;
			}
			sprintf(inputFilenameCstr, "%s", inputFilename);

			try {
				delete this->pictureBox2->Image;

				Model model{
					inputFilenameCstr,
					unmanaged->outputFile,
					myRGB(this->sliderR->Value, this->sliderG->Value, this->sliderB->Value),
					(uchar)this->sliderTolerance->Value
				};

				uint timeMs = model.run(loopXTimes, threadsSelected(), useAsmSelected());
				printInfo(timeMs.ToString() + " ms" + (loopXTimes > 1 ? (" / " + loopXTimes.ToString()) : ""));
				
				model.write();
				auto outputFile = gcnew String(unmanaged->outputFile);
				try {
					this->pictureBox2->Image = Image::FromFile(outputFile);
				}
				catch (...) {
					MessageBox::Show("Can't open output file: " + outputFile, "ERROR");
				}
			}
			catch (std::exception e) {
				String^ error = gcnew String(e.what());
				MessageBox::Show(error, "ERROR");
			}
		}

		private: System::Void runButton_Click(System::Object^ sender, System::EventArgs^ e) {
			run(1);
		}

		private: System::Void runX10Button_Click(System::Object^ sender, System::EventArgs^ e) {
#ifdef BENCHMARK
			benchmark();
#else
			run(10);
#endif
		}

		void setSettings() {
			int sizeOption = getCurrentImageOption();
			delete inputFilename;
			inputFilename = gcnew String(unmanaged->inputFiles[sizeOption]);

			auto rgb = unmanaged->targetColors[sizeOption];
			auto tolerance = unmanaged->tolerances[sizeOption];
			this->sliderR->Value = rgb.r;
			this->labelR2->Text = rgb.r.ToString();
			this->sliderG->Value = rgb.g;
			this->labelG2->Text = rgb.g.ToString();
			this->sliderB->Value = rgb.b;
			this->labelB2->Text = rgb.b.ToString();
			this->sliderTolerance->Value = tolerance;
			this->labelTolerance2->Text = tolerance.ToString();
		}
		private: System::Void largeImage_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			setSettings();
			setImage1();
		}
		private: System::Void mediumImage_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			setSettings();
			setImage1();
		}
		private: System::Void smallImage_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
			setSettings();
			setImage1();
		}

		void benchmark() {
			const int THREADS_OPTIONS = 7;
			int threads[THREADS_OPTIONS] = { 1, 2, 4, 8, 16, 32, 64 };
			for (int size = 0; size < 3; size++) {
				Model model{
					unmanaged->inputFiles[size],
					unmanaged->outputFile,
					unmanaged->targetColors[size],
					unmanaged->tolerances[size]
				};
				for (int isAsm = 0; isAsm < 2; isAsm++) {
					for (int threadsIdx = 0; threadsIdx < THREADS_OPTIONS; threadsIdx++) {
						uint timeMs = model.run(100, threads[threadsIdx], isAsm);
#ifdef CSV
						cout
							<< unmanaged->inputFiles[size]
							<< "," << (isAsm ? "asm" : "cpp")
							<< "," << threads[threadsIdx]
							<< "," << std::fixed << std::setprecision(3) << timeMs / 100.0
							<< endl;
#else
						cout << std::left 
							<< "file: "    << std::setw(20) << unmanaged->inputFiles[size]
							<< "code: "    << std::setw(5) << (isAsm ? "asm" : "cpp")
							<< "threads: " << std::setw(4) << threads[threadsIdx]
							<< "time: "    << std::fixed << std::setprecision(3) << timeMs / 100.0 << " ms"
						    << endl;
#endif
					}
				}
			}
		}

		private: System::Void sliderR_Scroll(System::Object^ sender, System::EventArgs^ e) {
			this->labelR2->Text = this->sliderR->Value.ToString();
		}
		private: System::Void sliderG_Scroll(System::Object^ sender, System::EventArgs^ e) {
			this->labelG2->Text = this->sliderG->Value.ToString();
		}
		private: System::Void sliderB_Scroll(System::Object^ sender, System::EventArgs^ e) {
			this->labelB2->Text = this->sliderB->Value.ToString();
		}
		private: System::Void sliderTolerance_Scroll(System::Object^ sender, System::EventArgs^ e) {
			this->labelTolerance2->Text = this->sliderTolerance->Value.ToString();
		}
		private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
			delete inputFilename;
			inputFilename = this->openFileDialog1->FileName;
			setImage1();
			this->largeImage->Checked = false;
			this->mediumImage->Checked = false;
			this->smallImage->Checked = false;
		}
		private: System::Void otherButton_Click(System::Object^ sender, System::EventArgs^ e) {
			this->openFileDialog1->ShowDialog();
		}
};
}
