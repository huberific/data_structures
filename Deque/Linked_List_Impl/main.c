/*******************************************************************************
* Author:      Aaron Huber
* Description: main program for testing
*******************************************************************************/

#include "Deque.h"

int main(int args, char* argv[]) {

    struct Deque myDeque;
    
    initDeque(&myDeque);

    if(isEmpty(&myDeque))
        printf("deque is empty\n");

    printf("adding 0:9 to front of deque\n");

    for (int i = 0; i < 10; ++i)
        addFront(&myDeque, i);

    printDeque(&myDeque);

    printf("adding 0:9 to back of deque\n");

    for (int i = 0; i < 10; ++i)
        addBack(&myDeque, i);

    printDeque(&myDeque);

    printf("popping 3 from front of deque\n");

    for (int i = 0; i < 3; ++i)
        popFront(&myDeque);

    printDeque(&myDeque);

    printf("popping 3 from back of deque\n");

    for (int i = 0; i < 3; ++i)
        popBack(&myDeque);

    printDeque(&myDeque);

    clearDeque(&myDeque);

    printDeque(&myDeque);

    freeDeque(&myDeque);

    return 0;

}
