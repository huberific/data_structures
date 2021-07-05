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
struct stack {
    struct link* top;
};

/* link struct contains data and link to next item */
struct link {
    TYPE val;
    struct link* next;
};

/* initializes stack */
void initStack(struct stack*);

/* empties stack */
void freeStack(struct stack*);

/* pushes item to top of the stack */
void pushStack(struct stack*, TYPE);

/* returns top of the stack */
TYPE topStack(struct stack*);

/* removes top of the stack */
void popStack(struct stack*);

/* returns 0 if stack is not empty, else non-zero */
int isEmptyStack(struct stack*);
