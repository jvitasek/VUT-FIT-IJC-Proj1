// error.c
// Řešení IJC-DU1, příklad a), 21.3.2014
// Autor: Jakub Vitásek, FIT
// Přeloženo: gcc 4.6.4

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"

void FatalError(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
	exit(1);
}

void Warning(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);
	vfprintf(stderr, fmt, args);
	va_end(args);
}