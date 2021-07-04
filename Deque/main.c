/******************************************************************************
* Description: Main program for testing
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "Deque.h"

int main(int argc, char *argv[]) {

    struct Deque myDeque;
    dequeInit(&myDeque, 5);

    /*
    // add values to deque:
    for (int i = 0; i < 10; ++i) {
        dequeAddFront(&myDeque, i);
        printf("adding %d to front of deque\n", i);
        printf("deque cap = %d\n", myDeque.cap);
        printf("d->beg = %d\n", myDeque.beg);
    }

    // add values to deque:
    for (int i = 10; i < 20; ++i) {
        dequeAddBack(&myDeque, i);
        printf("adding %d to back of deque\n", i);
        printf("deque cap = %d\n", myDeque.cap);
        printf("d->beg = %d\n", myDeque.beg);
    }
    */

    dequeAddFront(&myDeque, 99);


    printf("front of deque = %d\n", dequeFront(&myDeque));
    printf("back of deque = %d\n", dequeBack(&myDeque));

    printAndEmptyDeque(&myDeque);

    dequeFree(&myDeque);

    return 0;
}
