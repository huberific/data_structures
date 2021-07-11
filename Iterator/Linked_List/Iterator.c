/*******************************************************************************
* Author:      Aaron Huber
* Description: Implementation file of Iterator of Doubly Linked List (deque)
*******************************************************************************/

#include "Iterator.h"

/* initiliazes iterator of a deque */
void initIterator(struct Deque* deq, struct Iterator* itr) {

    assert(deq != 0 && itr != 0);

    itr->d = deq;
    itr->currLink = itr->d->frontSentinel;

}

/* boolean check to see if there is a next link */
int hasNext(struct Iterator* itr) {

    assert(itr != 0);

    return (itr->currLink->next != itr->d->backSentinel);

}

/* returns value of next link */
TYPE next(struct Iterator* itr) {

    assert(itr != 0);

    itr->currLink = itr->currLink->next;

    return itr->currLink->val;

}

/* removes current link of iterator */
void removeItr(struct Iterator* itr) {

    assert(itr != 0);

    if (itr->currLink != itr->d->frontSentinel
            && hasNext(itr)) {

        itr->currLink->next->prev = itr->currLink->prev;
        itr->currLink->prev->next = itr->currLink->next;

        free(itr->currLink);
        itr->d->size--;

    }

}
