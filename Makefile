CFLAGS=-std=c99 -pedantic -Wall -O2 -lm
 
all: prvocisla prvocisla-inline steg-decode

error.o: error.c error.h
	gcc $(CFLAGS) -c error.c -o error.o

eratosthenes.o: error.h ppm.h bit-array.h
	gcc $(CFLAGS) -c eratosthenes.c -o eratosthenes.o
 
ppm.o: ppm.c ppm.h error.h bit-array.h
	gcc $(CFLAGS) -c ppm.c -o ppm.o
 
steg-decode.o: steg-decode.c error.h bit-array.h ppm.h
	gcc $(CFLAGS) -c steg-decode.c -o steg-decode.o
 
prvocisla: prvocisla.c error.o eratosthenes.o
	gcc $(CFLAGS) prvocisla.c error.o eratosthenes.o -o prvocisla

prvocisla-inline: prvocisla.c error.o eratosthenes.o
	gcc $(CFLAGS) -DUSE_INLINE prvocisla.c error.o eratosthenes.o -o prvocisla-inline
steg-decode: steg-decode.o ppm.o error.o eratosthenes.o
	gcc $(CFLAGS) steg-decode.o error.o ppm.o eratosthenes.o -o steg-decode
 
clean:
	rm -f *.o
	rm -f prvocisla steg-decode prvocisla-inline
	~