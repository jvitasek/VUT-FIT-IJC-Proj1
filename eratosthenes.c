// eratosthenes.c
// Řešení IJC-DU1, příklad a), 21.3.2014
// Autor: Jakub Vitásek, FIT
// Přeloženo: gcc 4.6.4

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "bit-array.h"
#include "error.h"
#include "ppm.h"

void Eratosthenes(BitArray_t *pole)
{
	unsigned long limit = BitArraySize(pole);
	unsigned long bounds = (unsigned long) sqrt(limit);

	// "Crossing off" non-prime values
	for(int i = 2; i < bounds; i++)
	{
		if((GetBit(pole,i)) == 0)
		{
			for(int j = 2; (i * j) < limit; j++)
				SetBit(pole, i*j, 1);
		}
	}
}