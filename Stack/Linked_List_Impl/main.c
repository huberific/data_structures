/*******************************************************************************
* Author:      Aaron Huber
* Description: Program to test linked list stack implementation
*******************************************************************************/

#include "Stack.h"

int main(int argc, char* argv[]) {

    struct Stack myStack;

    initStack(&myStack);

    printf("adding 0:9 to stack\n");

    for (int i = 0; i < 10; ++i)
        pushStack(&myStack, i);

    printStack(&myStack);

    printf("popping top 3 from stack\n");
    
    for (int i = 0; i < 3; ++i)
        popStack(&myStack);

    printStack(&myStack);

    if (!isEmptyStack(&myStack))
        printf("stack is not empty\n");
    else
        printf("stack is empty\n");

    freeStack(&myStack);

    printf("freeing stack now\n");

    if (!isEmptyStack(&myStack))
        printf("stack is not empty\n");
    else
        printf("stack is empty\n");

    return 0;

}
