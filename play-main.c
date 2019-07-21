
#include <stdio.h>

#include "function.h"
#include "convolution.h"

#include <stdlib.h>
#include <math.h>
#include <string.h>

double f1(double x);

double f2(double x);

int main(int argc, char** argv)
{
	double x;
	double first = 0;
	double last = 10;
	const int size = 20;
	double l = last - first;
	double d = l / size;
	
	double sum = 0;
	
	double func[size];
	memset(func, 0, sizeof func);
	
	for(int i = 0; i < size / 2; i++)
	{
		sum += f1(i);
		for(int j = i; j < i + size / 2; j++)
		{
			func[j] += f1(i) * f2(j - i);
		}
	}
	
	for(int i = 0; i < size; i++)
		printf("%d\t%f\n", i, func[i]);

	return 0;
}

double f1(double x)
{
	return x;
}

double f2(double x)
{
	if(x == 0)
		return 1;
	return 0;
}
