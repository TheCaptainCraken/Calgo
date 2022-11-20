/*
    This is Pietro's Linked List C library. It creates a new data type (element_t).
    This library has all the most used methods for linked lists; here is a complete list with a brief explanation of all:
        - element_t* create_element(void* data):                                creates a new list element.
        - append(element_t** head, void* data):                                 creates and appends a new element to the list.
        - void delete(element_t** head):                                        deletes the list and all the data saved in it.
        - void print_list(element_t* head, void (*print_function)(void*)):      prints the list using a user-defined function.
        - int length(element_t* head):                                          returns the length of the list.
        - void push(element_t** head, void* data):                              creates a new elements and pushes it to the start of the list.
*/

#include <stdlib.h>
#include <stdio.h>


/*
    This struct holds a void pointer to a block of data in memory and a pointer to the next element in the list
*/
typedef struct element_s {
    void* data;
    struct element_s* next; 
}element_t;

/*
    This function creates a a new list element.
    Parameters:
        - void* data:               A pointer to a block of data in memory.
    Returns:
        - element_t* element:       The new element. Returns NULL if malloc fails.
*/
element_t* create_element(void*);


/*
    This function will create and append a new element at the end of a list.
    Parameters:
        - element_t** head:     A double pointer to the first element of the list.
        - void* data:           A pointer to a block of data in memory.
*/
void append(element_t**, void*);


/*
    This function deletes all the elements of a list (including the data pointed by the data pointer).
    Parameters:
        - element_t** head:     A double pointer to the first element of the list.
*/
void delete(element_t**);


/*
    This function will print all the elements of a list using a user-defined print function.
    Parameters:
        - element_t* head:                  A pointer to the first element of the list.
        - void (*print_function)(void*):    A pointer to a function that takes a pointer to a block of data and prints the data.
*/
void print_list(element_t*, void (*print_function)(void*));


/*
    This function will find the length of a list in number of elements.
    Parameters:
        - element_t* head:      A pointer to the first element of the list.
*/
int length(element_t*);


/*
    This function will create a new element and push it at the start of the list.
    Parameters:
        - element_t** head:     A double pointer to the first element of the list.
        - void* data:           A pointer to a block of data in memory.
*/
void push(element_t**, void*);


int insert_at_index(element_t**, void*, int);