
#include <stdio.h>

#include "function.h"
#include "convolution.h"

#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv)
{
	double x;
	struct function f;
	f.first = 0;
	f.last = 4;
	f.size = 1000;
	double l = (f.last - f.first) / f.size;
	f.func = (double*) malloc(f.size * sizeof(double) );
	for(int i = 0; i < f.size; i++)
	{
		x = l * i + f.first;
		f.func[i] = x * x; // TEST XXX
	}
	

	return 0;
}

