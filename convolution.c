#include "convolution.h"


struct function convolve(struct function a, struct function b)
{
	struct function c;
	if((a.first != b.first) || (a.last != b.last))
	{
		//error
		return 0;
	}
}
