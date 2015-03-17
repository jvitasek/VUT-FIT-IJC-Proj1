// ppm.c
// Řešení IJC-DU1, příklad a), 21.3.2014
// Autor: Jakub Vitásek, FIT
// Přeloženo: gcc 4.6.4

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "error.h"
#include "bit-array.h"
#include "ppm.h"

struct ppm *ppm_read(const char *filename)
{
	char p6[2] = {0};
	struct ppm *img;
	FILE *handle;
	int c, rgb;

	// Opening the file in argv[1]
	handle = fopen(filename, "rb");

	// Error Handler - if the file cannot be opened
	if(!handle)
		FatalError("Unable to open file %s!\n", filename);

    // Getting the first two chars
	fscanf(handle, "%c%c", &p6[0], &p6[1]);

    // Checking if the image follows the P6 format
	if(p6[0] != 'P' || p6[1] != '6')
		FatalError("The file %s is of invalid format (P6 error)!\n", filename);

	// Allocating memory for the image
	img = malloc(sizeof(struct ppm*));
	if(!img)
		FatalError("Unable to allocate memory for the file %s\n", filename);

	// Looping through the comments
	c = getc(handle);
	while(c == '#') {
		while (getc(handle) != '\n');
		c = getc(handle);
	}
	ungetc(c, handle);

	// Getting the width and height size
	if(fscanf(handle, "%u %u", &img->xsize, &img->ysize) != 2)
		FatalError("There was an error while reading width and height of the file %s!\n", filename);

	// Checking the component format
	if(fscanf(handle, "%d", &rgb) != 1)
		FatalError("There was an error while reading the component format of the file %s!\n", filename);

	// Checking if RGB is 255
	if(rgb != 255)
		FatalError("RGB has an invalid value in the file %s!\n", filename);

	while(fgetc(handle) != '\n') ;
	// Allocating memory for the image data
	img->data = malloc(img->xsize * img->ysize * 3);

	if(!img)
		FatalError("Unable to allocate memory for the file %s!\n", filename);

	// Reading the data to img->data
	if(fread(img->data, 3 * img->xsize, img->ysize, handle) != img->ysize)
		FatalError("There was an error while reading the data of the file %s!\n", filename);

	fclose(handle);
	return img;
}
 
 
int ppm_write(struct ppm *p, const char *filename)
{
	FILE *handle;

	//open file for output
	handle = fopen(filename, "wb");
	if (!handle) {
		exit(1);
	}

	//write the header file
	//image format
	fprintf(handle, "P6\n");

	//image size
	fprintf(handle, "%d %d\n", p->xsize, p->ysize);

	// rgb component depth
	fprintf(handle, "%d\n", 255);

	// pixel data
	fwrite(p->data, 3 * p->xsize, p->ysize, handle);
	fclose(handle);
	return 0;
}