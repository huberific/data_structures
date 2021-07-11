/*******************************************************************************
* Author:      Aaron Huber
* Description: Main program for testing
*******************************************************************************/

#include "Iterator.h"

int main(int argc, char* argv[]) {

    struct Deque myDeque;
    struct Iterator deqItr;
    TYPE currVal;

    initDeque(&myDeque);
    initIterator(&myDeque, &deqItr);

    /* add values to deque */
    for (int i = 0; i < 10; ++i)
        addFront(&myDeque, i);

    /* print deque contents */
    printf("deque contents = \n");

    while (hasNext(&deqItr)) {
        currVal = next(&deqItr);

        /* remove 4 from deque */
        if (currVal == 4)
            removeItr(&deqItr);

        printf("%d ", currVal);
    }

    printf("\n");

    /* re-init iterator to get pointer back to front sentinel (start) */
    initIterator(&myDeque, &deqItr);

    /* print deque contents, check that 4 has been removed */
    while (hasNext(&deqItr))
        printf("%d ", next(&deqItr));

    printf("\n");

    return 0;

}
