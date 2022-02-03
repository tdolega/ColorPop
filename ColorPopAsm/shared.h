#pragma once

//#define DEBUG
//#define CONSOLE
//#define BENCHMARK
#define CSV

#include <iostream>

using std::cout;
using std::endl;
using std::string;

typedef int32_t     myLONG;
typedef uint16_t    myWORD;
typedef uint32_t    myDWORD;
typedef uint64_t    uint;
typedef uint8_t     uchar;

#pragma pack(push, 1)

typedef struct btagBITMAPFILEHEADER {
    myWORD bfType;
    myDWORD bfSize;
    myWORD bfReserved1;
    myWORD bfReserved2;
    myDWORD bfOffBits;
} myBITMAPFILEHEADER, * myPBITMAPFILEHEADER;

typedef struct btagBITMAPINFOHEADER {
    myDWORD biSize;
    myLONG biWidth;
    myLONG biHeight;
    myWORD biPlanes;
    myWORD biBitCount;
    myDWORD biCompression;
    myDWORD biSizeImage;
    myLONG biXPelsPerMeter;
    myLONG biYPelsPerMeter;
    myDWORD biClrUsed;
    myDWORD biClrImportant;
} myBITMAPINFOHEADER, * myPBITMAPINFOHEADER;

typedef struct tagRGB {
    uchar b, g, r;

    tagRGB(uchar r, uchar g, uchar b) : r(r), g(g), b(b) {};
} myRGB, * myPRGB;

#pragma pack(pop)