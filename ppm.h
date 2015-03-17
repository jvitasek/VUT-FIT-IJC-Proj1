 // ppm.h
 // Řešení IJC-DU1, příklad a), 21.3.2014
 // Autor: Jakub Vitásek, FIT
 // Přeloženo: gcc 4.6.4

struct ppm {
	unsigned xsize;
	unsigned ysize;
	char *data; // RGB bajty, celkem 3*xsize*ysize
};
 
struct ppm *ppm_read(const char *filename);
int ppm_write(struct ppm *p, const char *filename);