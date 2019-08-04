
//TODO : add comments
//TODO : make a better standard for calculations

#include <stdio.h>

#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

#include "draw.hpp"

double fx(double x);

double impulse(double x);


int convolve(double* f1, double* f2, double* out, long int start, long int end);

void fourier-series(double* f, double* out, long int start, long int end, double sinStep);

double sum(double* f, long int start, long int end);

int main(int argc, char** argv)
{
	double x;
	long int first = 0;
	long int last = 1000;
	const int size = last - first;
	double l = last - first;
	double d = l / size;
	
	double sum = 0;
	
	double func[size * 2];
	memset(func, 0, sizeof func);
	
	double f1[size];
	double f2[size];
	
	for(long int i = first; i < last; i++)
	{
		f1[i - first] = (double) (i - 500) / 1000;
		f2[i - first] = 1;
	}
	
	convolve(f1, f2, func, first, last);
	
//	for(int i = 0; i < size * 2; i++)
//		printf("%d\t%f\n", i, func[i]);
		
	char image[1000][1000][3] = {0};
	
	int p;
	
	short h[9] = {0, 2, 0, 0, 0, 0, 1000, 1000, 24};
	FILE *f = fopen("2.tga", "wb");
	fwrite(h, 18, 1, f);



	
	for(int i = 0; i < 1000; i++)
	{
		p = f1[i] + 500 > 1000 ? 1000 : f1[i] + 500;
		p = p < 0 ? 0 : p;
		image[i][p][0] = 255;
		p = f2[i] + 500 > 1000 ? 1000 : f2[i] + 500;
		p = p < 0 ? 0 : p;
		image[i][p][1] = 255;
		p = func[i] + 500 > 1000 ? 1000 : func[i] + 500;
		p = p < 0 ? 0 : p;
		image[i][p][2] = 255;
	}
	image[500][500][0] = 100;
	image[500][500][1] = 200;
	image[500][500][2] = 150;


	for(int i = 0; i < 1000; i++)
	for(int j = 0; j < 1000; j++)
		fwrite(image[j][i], 3, 1, f);

	fclose(f);

	return 0;
}

double fx(double x)
{
	return x;
}

double impulse(double x)
{
	if(x == 0)
		return 1;
	return 0;
}


int convolve(double* f1, double* f2, double* out, long int start, long int end)
{

	long int length = end - start;
	
	for(int i = start; i < end; i++)
	{
		for(int j = i; j < i + length; j++)
		{
			out[j] += f1[i] * f2[j - i];
		}
	}	
	
	return 0;
}



double sum(double* f, long int start, long int end)
{
	double s = 0;
	for(long int i = start; i < end; i++)
		s += f[i];
	return s;
}





void fourier-series(double* f, double* outSin, double* outCos, long int start, long int end, long int max_n, double sinStep)
{
	long int T = end - start;
	double dc = sum(f, start, end) / T;
	outSin[0] = dc;
	outCos[0] = dc;
	
	double sinCoef;
	double cosCoef;
	
	for(long int i = 1; i < max_n; i++)
	{
		;//TODO
	}


}





























