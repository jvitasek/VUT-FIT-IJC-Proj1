 // bit-array.h
 // Řešení IJC-DU1, příklad a), 21.3.2014
 // Autor: Jakub Vitásek, FIT
 // Přeloženo: gcc 4.6.4

typedef unsigned long BitArray_t;

void Eratosthenes(BitArray_t *pole);

#define RANGE (8*sizeof(unsigned long))

#define BitArray(jmeno_pole,velikost) \
		BitArray_t jmeno_pole[1 + velikost/RANGE + ((velikost%RANGE) != 0)] = {velikost, 0};

#ifdef USE_INLINE

inline unsigned long BitArraySize(BitArray_t *array) {
	return array[0];
}

inline int SetBit(BitArray_t *array, unsigned long index, int vyraz) {
	if((index) > (BitArraySize(array) - 1)) {
		fprintf(stderr, "Index %ld mimo rozsah 0..%ld\n", (long)index, BitArraySize(array)-1);
	}
	array[((index)/RANGE)+1] = (vyraz) ? (array[((index)/RANGE)+1] | (1ULL<<((index)%RANGE))) : (array[((index)/RANGE)+1] & ~(1ULL<<((index)%RANGE)));
	return 0;
}

inline int GetBit(BitArray_t *array, unsigned long index) {
	if((index) > (BitArraySize(array) - 1)) {
		fprintf(stderr, "Index %ld mimo rozsah 0..%ld\n", (long)index, BitArraySize(array)-1);
	}
	return ((array[((index)/RANGE)+1] & (1ULL<<((index)%RANGE))) ? 1 : 0);
}

#else

#define BitArraySize(jmeno_pole) \
 		jmeno_pole[0]

#define SetBit(jmeno_pole, index, vyraz) \
 		(index >= jmeno_pole[0]) ? (fprintf(stderr, "Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)jmeno_pole[0])) : (jmeno_pole[((index)/RANGE)+1] = (vyraz) ? (jmeno_pole[((index)/RANGE)+1] | (1ULL<<((index)%RANGE))) : (jmeno_pole[((index)/RANGE)+1] & ~(1ULL<<((index)%RANGE))));

#define GetBit(jmeno_pole, index) \
 		(index >= jmeno_pole[0]) ? (fprintf(stderr, "Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, (unsigned long)jmeno_pole[0])) : ((jmeno_pole[((index)/RANGE)+1] & (1ULL<<((index)%RANGE))) ? 1 : 0)
#endif

#define DU1__GET_BIT(p,i) \
 		(p[((i)/RANGE)+1] & (1ULL<<((i)%RANGE))) ? 1 : 0

#define DU1__SET_BIT(p,i,b) \
 		p[((i)/RANGE)+1] = (b) ? (p[((i)/RANGE)+1] | (1ULL<<((i)%RANGE))) : (p[((i)/RANGE)+1] & ~(1ULL<<((i)%RANGE)));
