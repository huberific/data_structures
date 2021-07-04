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
    for (int i = 5; i > 0; --i) {
        dequeAddFront(&myDeque, i);
        printf("adding %d to front of deque\n", i);
        printf("deque cap = %d\n", myDeque.cap);
        printf("d->beg = %d\n", myDeque.beg);
    }

    // add values to deque:
    for (int i = 6; i < 11; ++i) {
        dequeAddBack(&myDeque, i);
        printf("adding %d to back of deque\n", i);
        printf("deque cap = %d\n", myDeque.cap);
        printf("d->beg = %d\n", myDeque.beg);
    }

    printDeque(&myDeque);

    dequeRemoveFront(&myDeque);
    dequeRemoveFront(&myDeque);
    dequeRemoveFront(&myDeque);

    dequeRemoveBack(&myDeque);
    dequeRemoveBack(&myDeque);

    printDeque(&myDeque);

    // add values to deque:
    for (int i = 11; i < 15; ++i) {
        dequeAddBack(&myDeque, i);
        printf("adding %d to back of deque\n", i);
        printf("deque cap = %d\n", myDeque.cap);
        printf("d->beg = %d\n", myDeque.beg);
    }

    printDeque(&myDeque);

    for (int i = dequeSize(&myDeque); i > 0; --i)
        dequeRemoveFront(&myDeque);

    printDeque(&myDeque);

    dequeFree(&myDeque);

    return 0;
}
