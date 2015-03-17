 // prvocisla.c
 // Řešení IJC-DU1, příklad a), 21.3.2014
 // Autor: Jakub Vitásek, FIT
 // Přeloženo: gcc 4.6.4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bit-array.h"
#include "error.h"

int main(void)
{
	BitArray(pole,101000000L);
	Eratosthenes(pole);
	unsigned long limit = BitArraySize(pole);

	int k = 0;
	unsigned long lastTen[10] = {0};

	for(int i = limit-1; k < 10; --i)
	{
		if((GetBit(pole,i)) == 0)
		{
			lastTen[k] = i;
			k++;
		}
	}
	for(int i = 9; i >= 0; --i)
		printf("%lu\n", lastTen[i]);
}