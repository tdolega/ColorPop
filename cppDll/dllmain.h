#pragma once
#include <cstdint>


typedef uint64_t    uint;
typedef uint8_t     uchar;

#pragma pack(push, 1)

typedef struct tagRGB {
    uchar b, g, r;

    tagRGB(uchar r, uchar g, uchar b) : r(r), g(g), b(b) {};
} myRGB, * myPRGB;

#pragma pack(pop)

/*
 * convert RGB to single grayscale value
 *
 * return grayscale value of given RGB
 */
uchar toGreyscale(const myRGB* pixel);

/*
 * checks 3 colors of pixel with function inColorRange
 *
 * return if input pixel is close to target pixel in color
 */
bool inColorRange(const myRGB* pixel, myRGB* cutoffLow, myRGB* cutoffHigh);

/*
 * C++ implementation
 */
extern "C" __declspec(dllexport) void cppImp(const uchar* input, uchar* output, const int rei, const int x, myRGB* cutoffLow, myRGB* cutoffHigh);
