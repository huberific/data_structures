/******************************************************************************
* Description: Main program for testing
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "Deque.h"

int main(int argc, char *argv[]) {

    struct Deque myDeque;
    dequeInit(&myDeque, 5);

    // add values to deque:
    for (int i = 0; i < 10; ++i) {
        dequeAddFront(&myDeque, i);
        printf("adding %d to front of deque\n", i);
        printf("deque cap = %d\n", myDeque.cap);
    }

    printDeque(&myDeque);

    freeDeque(&myDeque);

    return 0;
}
