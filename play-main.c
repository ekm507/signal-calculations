
#include <stdio.h>

#include <stdlib.h>
#include <math.h>
#include <string.h>

double fx(double x);

double impulse(double x);


int convolve(double* f1, double* f2, double* out, long int start, long int end);


int laplace(double f, double out, double start, double end); // TODO


int main(int argc, char** argv)
{
	double x;
	long int first = 0;
	long int last = 10;
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
		f1[i - first] = fx(i);
		f2[i - first] = fx(i);
	}
	
	convolve(f1, f2, func, first, last);
	
	for(int i = 0; i < size * 2; i++)
		printf("%d\t%f\n", i, func[i]);

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


