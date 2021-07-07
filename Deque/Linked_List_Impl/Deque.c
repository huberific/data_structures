/*******************************************************************************
* Author:      Aaron Huber
* Description: Implementation file of Deque using a doubly-linked list
*******************************************************************************/

#include "Deque.h"

/* initializes deque */
void initDeque(struct Deque* d) {

    assert(d != 0);

    /* note must create sentinels before pointing */
    d->frontSentinel = (struct DLink*)malloc(sizeof(struct DLink));
    assert(d->frontSentinel != 0);

    d->backSentinel = (struct DLink*)malloc(sizeof(struct DLink));
    assert(d->backSentinel != 0);

    /* set pointers of front sentinel */
    d->frontSentinel->next = d->backSentinel;
    d->frontSentinel->prev = NULL;

    /* set pointers of back sentinel */
    d->backSentinel->next = NULL;
    d->backSentinel->prev = d->frontSentinel;

    d->size = 0;

}

/* clears all links from deque */
void clearDeque(struct Deque* d) {

    assert(d != 0);

    while(!isEmpty(d))
        popFront(d);

}

void freeDeque(struct Deque* d) {

    /* clearing deque will remove link dynamic memory */
    if(!isEmpty(d))
        clearDeque(d);

    /* free dynamic memory of sentinels */
    free(d->frontSentinel);
    free(d->backSentinel);

}

/* adds item to front of deque */
void addFront(struct Deque* d, TYPE newVal) {

    _addLink(d, d->frontSentinel->next, newVal);

}

/* adds item to back of deque */
void addBack(struct Deque* d, TYPE newVal) {

    _addLink(d, d->backSentinel, newVal);

}

/* removes front item from deque */
void popFront(struct Deque* d) {

    _removeLink(d, d->frontSentinel->next->next);

}

/* removes back item from deque */
void popBack(struct Deque* d) {

    _removeLink(d, d->backSentinel);

}

/* returns 0 if deque is not empty, else returns non-zero */
int isEmpty(struct Deque* d) {

    assert(d != 0);

    return(d->frontSentinel->next == d->backSentinel && 
            d->backSentinel->prev == d->frontSentinel &&
            d->size == 0);

}

/* helper function - adds link BEFORE link passed */
void _addLink(struct Deque* d, struct DLink* lnk, TYPE newVal) {

    assert(d != 0);

    /* create new DLink */
    struct DLink* newDLink = (struct DLink*)malloc(sizeof(struct DLink));
    assert(newDLink != 0);

    /* save passed in value into DLink */
    newDLink->val = newVal;

    /* add pointers of new DLink */
    newDLink->prev = lnk->prev;
    newDLink->next = lnk;

    /* update adjacent DLink pointers to point to new DLink */
    lnk->prev->next = newDLink;
    lnk->prev = newDLink;

    d->size++;
}

/* helper function - removes link before link passed */
void _removeLink(struct Deque* d, struct DLink* lnk) {

    assert(d != 0);

    if (!isEmpty(d)) {

        struct DLink* curr = lnk->prev;
        curr->prev->next = lnk;
        lnk->prev = curr->prev;

        free(curr);
        curr = NULL;

        d->size--;

    }

}

/* returns front link value of deque */
TYPE front(struct Deque* d) {

    assert(d != 0);

    if (!isEmpty(d))
        return d->frontSentinel->next->val;

}

/* returns back link value of deque */
TYPE back(struct Deque* d) {

    assert(d != 0);

    if (!isEmpty(d))
        return d->backSentinel->prev->val;

}

/* print contents of deque */
void printDeque(struct Deque* d) {

    assert(d != 0);

    if (!isEmpty(d)) {

        struct DLink* ptr = d->frontSentinel->next;

        /* iterate through linked list until ptr is at backsentinel */
        while (ptr != d->backSentinel) {

            printf("%d ", ptr->val);
            ptr = ptr->next;            /* go to next link */

        }

        printf("\n-----\nfront = %d, back = %d\n", front(d), back(d));

    }
    else
        printf("deque is empty\n");

}
