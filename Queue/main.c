/******************************************************************************
* Description: Main program for testing
******************************************************************************/

#include "Queue.h"

int main(int args, char* argv[]) {

    struct Queue myQueue;
    initQueue(&myQueue);

    printQueue(&myQueue);
    
    push(&myQueue, 1);
    printQueue(&myQueue);

    push(&myQueue, 2);
    printQueue(&myQueue);

    push(&myQueue, 3);
    printQueue(&myQueue);

    push(&myQueue, 4);
    printQueue(&myQueue);
    
    push(&myQueue, 5);
    printQueue(&myQueue);

    pop(&myQueue);
    printQueue(&myQueue);

    pop(&myQueue);
    printQueue(&myQueue);

    pop(&myQueue);
    printQueue(&myQueue);

    pop(&myQueue);
    printQueue(&myQueue);

    pop(&myQueue);
    printQueue(&myQueue);

    deleteQueue(&myQueue);

    return 0;
}
