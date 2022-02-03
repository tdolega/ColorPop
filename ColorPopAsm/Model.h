#pragma once

#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <iterator>
#include <chrono>
#include <thread>
#include <stdexcept>
#include <Windows.h>
#include <algorithm>

#include "shared.h"


class Model {
    typedef void(_fastcall* dllProc)(const uchar* input, uchar* output, const int rei, const int x, myRGB* cutoffLow, myRGB* cutoffHigh);
    
    HINSTANCE asmDllHandle = LoadLibrary(L"asmDll.dll");
    dllProc asmProc = nullptr;

    HINSTANCE cppDllHandle = LoadLibrary(L"cppDll.dll");
    dllProc cppProc = nullptr;

    myPBITMAPFILEHEADER fileHeader{};
    myPBITMAPINFOHEADER infoHeader{};
    uchar * inputBuffer = nullptr,   // input file buffer
          * outputBuffer = nullptr;  // output file buffer
    char  * inFilePath,
          * outFilePath;
    uint rows{},                     // bitmap rows
        cols{},                      // bitmap columns
        fileSize{},                  // [B] size of whole file
        endOffset{};                 // [B] padding on each row end in bytes

    myRGB* cutoffLow = new myRGB(0, 0, 0);
    myRGB* cutoffHigh = new myRGB(0, 0, 0);

    void debug(const string& msg, const string& prefix = ">>");

    bool error(const string& msg);

public:
    Model(char* inFilePath, char* outFilePath, myRGB targetColor, uchar tolerance)
        : inFilePath(inFilePath), outFilePath(outFilePath) {
        cutoffLow->r = max(targetColor.r - tolerance, 0);
        cutoffLow->g = max(targetColor.g - tolerance, 0);
        cutoffLow->b = max(targetColor.b - tolerance, 0);

        cutoffHigh->r = min(targetColor.r + tolerance, 255);
        cutoffHigh->g = min(targetColor.g + tolerance, 255);
        cutoffHigh->b = min(targetColor.b + tolerance, 255);

        if (asmDllHandle)
            asmProc = (dllProc)GetProcAddress(asmDllHandle, "asmImp");
        if (asmProc == nullptr)
            error("Couldn't load asm dll.");

        if (cppDllHandle)
            cppProc = (dllProc)GetProcAddress(cppDllHandle, "cppImp");
        if (cppProc == nullptr)
            error("Couldn't load cpp dll.");
    };
    ~Model();

    /*
     * Read input file
     * if (is bitmap)
     *  load into memory
     *
     * return failed
     */
    bool read();

    /*
     * write output buffer to file
     *
     * return failed
     */
    bool write();

    /*
     * calculate index of last element of given row
     *
     * return index
     */
    int rowEndIdx(uint y) const;

    void thread(std::atomic<uint>& gy, void(Model::*imp)(const uchar*, uchar* output, const int, const int, myRGB*, myRGB*));

    void runThreads(uint concurrent, bool useAsm);

    uint benchmark(uint n, uint concurrent, bool useAsm);

    uint run(uint n, uint concurrent, bool useAsm);

    void asmRow(const uchar* input, uchar* output, const int rei, const int cols, myRGB* cutoffLow, myRGB* cutoffHigh);

    void cppRow(const uchar* input, uchar* output, const int rei, const int cols, myRGB* cutoffLow, myRGB* cutoffHigh);
};
