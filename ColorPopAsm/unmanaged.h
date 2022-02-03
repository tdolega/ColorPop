#pragma once

#include "shared.h"

public class HolderOfUnmanagedStuff {
public:
	char* inputFiles[3] = {
		".\\data\\large.bmp",
		".\\data\\medium.bmp",
		".\\data\\small.bmp",
	};
	char* outputFile = ".\\data\\_out.bmp";

	myRGB targetColors[3] = {
		myRGB(255, 156, 29),
		myRGB(254, 205, 6),
		myRGB(254, 0, 254),
	};

	uchar tolerances[3] = {
		120,
		120,
		20,
	};

};