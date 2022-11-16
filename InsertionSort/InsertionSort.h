#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int compare_int(void*, void*);
int compare_float(void*, void*);

void InsertionSort(void*, int, size_t, int (*compare_function)(void*, void*));