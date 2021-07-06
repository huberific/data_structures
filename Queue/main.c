/******************************************************************************
* Description: Main program for testing
******************************************************************************/

#include "Queue.h"

int main(int args, char* argv[]) {

    struct Queue myQueue;
    initQueue(&myQueue);

    printf("adding 0:9 into queue\n");

    for (int i = 0; i < 10; ++i)
        push(&myQueue, i);

    printf("queue front = %d\n", front(&myQueue));

    printQueue(&myQueue);

    printf("popping 3 from queue\n");

    for (int i = 0; i < 3; ++i)
        pop(&myQueue);

    printf("queue front = %d\n", front(&myQueue));

    printQueue(&myQueue);

    printf("adding 0:2 into queue\n");

    for (int i = 0; i < 3; ++i)
        push(&myQueue, i);

    printf("queue front = %d\n", front(&myQueue));
    printQueue(&myQueue);

    printf("freeing queue\n");

    deleteQueue(&myQueue);

    printQueue(&myQueue);

    return 0;
}
