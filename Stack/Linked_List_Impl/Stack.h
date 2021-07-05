/*******************************************************************************
* Author:      Aaron Huber
* Description: Interface file of Stack using a forward linked list
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef TYPE 
#define TYPE int
#endif

/* stack struct holds top of stack pointing to first item in list */
struct Stack {
    struct Link* top;
};

/* link struct contains data and link to next item */
struct Link {
    TYPE val;
    struct Link* next;
};

/* initializes stack */
void initStack(struct Stack*);

/* empties stack */
void freeStack(struct Stack*);

/* pushes item to top of the stack */
void pushStack(struct Stack*, TYPE);

/* returns top of the stack */
TYPE topStack(struct Stack*);

/* removes top of the stack */
void popStack(struct Stack*);

/* returns 0 if stack is not empty, else non-zero */
int isEmptyStack(struct Stack*);

/* prints contents of stack */
void printStack(struct Stack*);
