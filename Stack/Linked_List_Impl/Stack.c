/*******************************************************************************
* Author:      Aaron Huber
* Description: Implementation file of Stack using a forward linked list
*******************************************************************************/

#include "Stack.h"

/* initializes stack */
void initStack(struct Stack* s) {

    assert(s != 0);

    s->top = NULL;

}

/* empties stack */
void freeStack(struct Stack* s) {

    assert(s != 0);

    /* cycle through each link and free dyn memory */
    while(s->top != NULL) {

        struct Link* temp = s->top->next;
        free(s->top);
        s->top = temp;
        temp = NULL;
    }

}

/* pushes item to top of the stack */
void pushStack(struct Stack* s, TYPE newVal) {

    assert(s != 0);

    /* create new link */
    struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
    assert(newLink != 0);

    /* temp hold current top link mem location */
    struct Link* temp = s->top;
    
    /* set top to new link mem location and apply attributes */
    s->top = newLink;
    newLink->val = newVal;
    newLink->next = temp;
    temp = NULL;

}

/* returns top of the stack */
TYPE topStack(struct Stack* s) {

    assert(s != 0);

    if (!isEmptyStack(s)) 
        return s->top->val;
    
}

/* removes top of the stack */
void popStack(struct Stack* s) {
    
    assert(s != 0);

    if (!isEmptyStack(s)) {

        struct Link* temp = s->top->next;
        free(s->top);
        s->top = temp;

    }
        
}

/* returns 0 if stack is not empty, else non-zero */
int isEmptyStack(struct Stack* s) {

    assert(s != 0);

    return (s->top == NULL);
    
}

/* prints contents of stack */
void printStack(struct Stack* s) {

    assert(s != 0);

    struct Link* temp = s->top;

    if(!isEmptyStack(s))
        printf("top of stack = %d\n", topStack(s));
    
    while(temp != NULL) {

        printf("%d\n", temp->val);
        temp = temp->next;

    }

}
