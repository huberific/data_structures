/*******************************************************************************
* Author:      Aaron Huber
* Description: Interface file of Deque using a doubly-linked list
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef TYPE
#define TYPE int
#endif 

struct DLink {
    
    TYPE val;
    struct DLink* next;
    struct DLink* prev;

};

struct Deque {

    int size;
    struct DLink* frontSentinel;
    struct DLink* backSentinel;

};

/* initializes deque */
void initDeque(struct Deque*);

/* frees dynamic memory of deque */
void freeDeque(struct Deque*);

/* clears all links from deque */
void clearDeque(struct Deque*);

/* adds item to front of deque */
void addFront(struct Deque*, TYPE);

/* adds item to back of deque */
void addBack(struct Deque*, TYPE);

/* removes front item from deque */
void popFront(struct Deque*);

/* removes back item from deque */
void popBack(struct Deque*);

/* returns 0 if deque is not empty, else returns non-zero */
int isEmpty(struct Deque*);

/* helper function - adds link BEFORE link passed */
void _addLink(struct Deque*, struct DLink*, TYPE);

/* helper function - removes link BEFORE link passed */
void _removeLink(struct Deque*, struct DLink*);

/* returns front link value of deque */
TYPE front(struct Deque*);

/* returns back link value of deque */
TYPE back(struct Deque*);

/* print contents of deque */
void printDeque(struct Deque*);
