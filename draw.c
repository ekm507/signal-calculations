#include "draw.hpp"
#include <stdio.h>

FILE *f;
short width;
short height;

void createFile(const char* filename, short imageWidth, short imageHeight)
{
	width = imageWidth;
	height = imageHeight;
	short h[9] = {0, 2, 0, 0, 0, 0, width, height, 24};
	f = fopen(filename, "wb");
	fwrite(h, 18, 1, f);
}

void writeImage(char*** image)
{
	for(int i = 0; i < height; i++)
		for(int j = 0; j < width; j++)
			fwrite(image[i][j], 3, 1, f);
}

void closeFile()
{
	fclose(f);
}

