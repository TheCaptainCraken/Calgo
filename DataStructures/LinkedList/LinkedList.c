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


#include "LinkedList.h"


/*
    This function creates a a new list element.
    Parameters:
        - void* data:               A pointer to a block of data in memory.
    Returns:
        - element_t* element:       The new element. Returns NULL if malloc fails.
*/
element_t* create_element(void* data) {
    element_t* new_element = (element_t*) malloc(sizeof(element_t));
    if (new_element == NULL) {
        fprintf(stderr, "malloc failed.\n");
        return NULL;
    }

    new_element->data = data;
    new_element->next = NULL;

    return new_element;
}


/*
    This function will create and append a new element at the end of a list.
    Parameters:
        - element_t** head:     A double pointer to the first element of the list.
        - void* data:           A pointer to a block of data in memory.
*/
void append(element_t** head, void* data) {

    element_t* new_element = create_element(data);
    if (*head == NULL) {
        *head = new_element;
    } else {
        element_t* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_element;
    }
}


/*
    This function deletes all the elements of a list (including the data pointed by the data pointer).
    Parameters:
        - element_t** head:     A double pointer to the first element of the list.

    TODO: fix unidentified bug
*/
void delete(element_t** head) {
    element_t* tmp = (*head);
    while (tmp != NULL) {
        printf("%p\n", tmp);
        tmp = tmp->next;
        free((*head)->data);
        free((*head));
        *head = tmp;
    }
}


/*
    This function will print all the elements of a list using a user-defined print function.
    Parameters:
        - element_t* head:                  A pointer to the first element of the list.
        - void (*print_function)(void*):    A pointer to a function that takes a pointer to a block of data and prints the data.
*/
void print_list(element_t* head, void (*print_function)(void*)) {
    element_t* tmp = head;

    while (tmp != NULL) {
        print_function(tmp->data);
        tmp = tmp->next;
    }
}


/*
    This function will find the length of a list in number of elements.
    Parameters:
        - element_t* head:      A pointer to the first element of the list.
*/
int length(element_t* head) {
    int len;
    for (len = 0; head != NULL; len++) {
        head = head->next;
    }
    return len;
}


/*
    This function will create a new element and push it at the start of the list.
    Parameters:
        - element_t** head:     A double pointer to the first element of the list.
        - void* data:           A pointer to a block of data in memory.
*/
void push(element_t** head, void* data) {
    element_t* new_element = create_element(data);

    new_element->next = *head;
    *head = new_element;
}

int insert_at_index(element_t** head, void* data, int index) {

    if (index < 0) {
        return 0;
    } else if (index == 0) {
        push(head, data);
    } else {

        element_t* new_element = create_element(data);

        element_t* tmp = *head;
        for (int i = 0; i < index - 1; i++) {
            if (tmp == NULL) {
                return 0;
            }
            tmp = tmp->next;
        }
        if (tmp == NULL) {
            return 0;
        }
        element_t* tmp2 = tmp->next;
        tmp->next = new_element;
        new_element->next = tmp2;
    }
}