#include "pch.h"

#include "dllmain.h"

uchar inline toGreyscale(const myRGB* pixel) {
	return (uchar)(0.2989f * pixel->r + 0.5870f * pixel->g + 0.1140f * pixel->b);
}

bool inline inColorRange(const myRGB* pixel, myRGB* cutoffLow, myRGB* cutoffHigh) {
	return cutoffLow->r <= pixel->r && pixel->r <= cutoffHigh->r
		&& cutoffLow->g <= pixel->g && pixel->g <= cutoffHigh->g
		&& cutoffLow->b <= pixel->b && pixel->b <= cutoffHigh->b;
}

extern "C" __declspec(dllexport) void cppImp(const uchar* input, uchar* output, const int rei, const int x, myRGB* cutoffLow, myRGB* cutoffHigh) {
	uint idx = rei - 3 * x;
	myRGB* in = (myRGB*)&input[idx];
	myRGB* out = (myRGB*)&output[idx];

	if (inColorRange(in, cutoffLow, cutoffHigh))
		*out = *in;
	else
		out->r = out->g = out->b = toGreyscale(in);
}