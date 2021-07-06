/*******************************************************************************
* Author:       Aaron Huber
* Description:  Interface file of a Queue using a Linked List w/ Sentinel
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef TYPE
#define TYPE int
#endif

struct Link {

    TYPE val;
    struct Link* next;

};

struct Queue {

    struct Link* front;
    struct Link* back;

};

/* initializes queue and sentinel */
void initQueue(struct Queue*);

/* adds item to back of queue */
void push(struct Queue*, TYPE);

/* returns front of queue value */
TYPE front(struct Queue*);

/* removes front of queue */
void pop(struct Queue*);

/* returns 0 if queue is not empty, else non-zero */
int isEmpty(struct Queue*);

/* print contents of queue */
void printQueue(struct Queue*);

/* empties queue */
void deleteQueue(struct Queue*);
