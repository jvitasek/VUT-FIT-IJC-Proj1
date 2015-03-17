// steg-decode.c
// Řešení IJC-DU1, příklad a), 21.3.2014
// Autor: Jakub Vitásek, FIT
// Přeloženo: gcc 4.6.4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bit-array.h"
#include "error.h"
#include "ppm.h"

#define LIMIT 3*1000*1000

int main(int argc, char const *argv[])
{
	char const *filename = 0;

	if(argc <= 2)
		filename = argv[1];
	else
		FatalError("Error while opening the file %s!\n", filename);

	struct ppm *p_a = ppm_read(filename);

	BitArray(p,(1000*1000*3));
	Eratosthenes(p);
	free(p_a);
	return 0;
}