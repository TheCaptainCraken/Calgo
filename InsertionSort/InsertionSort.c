#include "InsertionSort.h"

//returns 1 if n1 > n2 else 0
int compare_int(void* n1, void* n2){
    int a = *((int*) n1);
    int b = *((int*) n2);

    if(a > b)
        return 1;
    else
        return 0;

}

//returns 1 if n1 > n2 else 0
int compare_float(void* n1, void* n2){
    float a = *((float*) n1);
    float b = *((float*) n2);

    if(a > b)
        return 1;
    else
        return 0;

}

//Insertion sort (pointer to the array, lenght of the array, size in bytes of the datatype of the array, pointer to a function that compares tro elements).
//The function must return 1 if the first argument is considered bigger than the second. Else 0 is expected.
void InsertionSort(void* array, int len, size_t size, int (*compare_function)(void*, void*)){
    if(len == 1)
        return;

    for(int j = 1; j < len; j++){
        void* tmp = malloc(size);
        if (tmp == NULL){
            fprintf(stderr, "malloc fail\n"); //just in case
            return;
        }
        memcpy(tmp, array + (size * j), size); // tmp = array[j]
        int i = j-1;
        while( i >= 0 && (*compare_function)(array + (size*i) ,tmp) == 1){ // array[i] > tmp and i >= 0
            memcpy(array + (size * (i+1)), array + (size*i), size); // array[i+1] = array[i]
            i--;
        }
        memcpy(array + (size * (i+1)), tmp, size); // array[i+1] = tmp
        free(tmp);
    }

    return;
}