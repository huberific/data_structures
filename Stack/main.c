/******************************************************************************
* Description: Main program for testing
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

int main(int argc, char *argv[]) {

    struct DynArr myStack;
    initDynArr(&myStack, 5);

    // add values to stack:
    for (int i = 0; i < 10; i++) {
        dynArrayPush(&myStack, i);
        printf("pushing %d onto stack\n", i);
        printf("stack cap = %d\n", myStack.cap);
    }

    printDynArr(myStack);
    
    for (int i = 0; i < 10; i++) {
        printf("top of stack = %d\n", dynArrayTop(&myStack));
        dynArrayPop(&myStack);
        printf("stack popped\n");
    }

    printDynArr(myStack);

    freeDynArr(&myStack);
}
