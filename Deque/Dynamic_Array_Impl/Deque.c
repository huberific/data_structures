/******************************************************************************
* Description: Interface file of a deque using a dynamic array
*
* Operations:  AddBack     --> best case O(1), worst O(n), avg O(1+)
*              RemoveBack  --> best case O(1), worst O(1), avg O(1)
*              AddFront    --> best case O(1), worst O(n), avg(1+)
*              RemoveFront --> best case O(1), worst O(1), avg(1)
*
******************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Deque.h"

// initializes a deque using dynamic array:
void dequeInit(struct Deque* d, int initCap) {

    assert(d != 0 && initCap > 0);

    d->data = (TYPE*)malloc(sizeof(TYPE) * initCap);
    assert(d->data != 0);

    d->size = d->beg = 0;     /* start beg indicator at array index 0 */
    d->cap  = initCap;
    
}

// resizes deque capacity using capacity passed in:
void _dequeSetCapacity(struct Deque* d, int newCap) {

    assert(d != 0);

    /* create new array to hold elements */
    TYPE* newData = (TYPE*)malloc(sizeof(TYPE) * newCap);

    /* for copying elements, note j used to wrap around array if needed */
    int i = 0, 
        j = d->beg;

    for (; i < dequeSize(d); ++i) {

        newData[i] = d->data[j++];

        /* if data wraps around */
        if (j >= d->cap)
            j = 0;
    }

    // free previous dynamic memory:
    free(d->data); 

    // assign newly resized array to struct object::
    d->data = newData;

    d->cap = newCap;

    // beg to start at index 0 when resized:
    d->beg = 0;

}

// returns the number of elements in the deque:
int dequeSize(struct Deque* d) {

    assert(d != 0);

    return d->size;

}

// adds new element to front of deque:
void dequeAddFront(struct Deque* d, TYPE val) {

    assert(d != 0);

    // check if there is space for new val, resize deque if not:
    if (dequeSize(d) >= d->cap)
        _dequeSetCapacity(d, 2 * d->cap);

    // place new value to the left of beg indicator:
    int idx = d->beg - 1;

    // if beg is at index 0, place new value at last index:
    if (idx < 0)
        idx = d->cap - 1;

    d->data[idx] = val;
    d->beg = idx;

    // increment size of deque:
    d->size++;

}

// adds new element to the back of deque:
void dequeAddBack(struct Deque* d, TYPE val) {

    assert(d != 0);

    // check if there is space for new val, resize deque if not:
    if (dequeSize(d) >= d->cap)
        _dequeSetCapacity(d, 2 * d->cap);

    // idx to hold last element position:
    int idx = d->beg + d->size;

    // if last index wraps around to front of array:
    if (idx >= d->cap)
        idx -= d->cap;

    d->data[idx] = val;

    // increment size of deque:
    d->size++;

}

// returns the front element of the deque:
TYPE dequeFront(struct Deque* d) {

    assert(dequeSize(d) > 0);

    return d->data[d->beg];

}

// returns the back element of the deque:
TYPE dequeBack(struct Deque* d) {

    assert(dequeSize(d) > 0);

    // idx to hold last element position:
    int idx = d->beg + d->size - 1;

    // if last element position has wrapped around to beginning of array:
    if (idx >= d->cap)
        idx -= d->cap;

    return d->data[idx];

}

// removes front element of deque:
void dequeRemoveFront(struct Deque* d) {

    assert(dequeSize(d) > 0);

    // increment beg indicator to point to next element:
    d->beg++;

    // account for beg indicator wrapping around to start of array:
    if (d->beg >= d->cap)
        d->beg = 0;

    // decrement size of deque:
    d->size--;

}

// removes back element of deque:
void dequeRemoveBack(struct Deque* d) {

    assert(dequeSize(d) > 0);

    // no change to beg indicator needed, only size attribute:
    d->size--;

}

// free dynamic memory:
void dequeFree(struct Deque* d) {

    assert(d != 0);

    // free up dynamic memory allocationed:
    free(d->data);
}

// prints contents of deque:
void printDeque(struct Deque* d) {

    int dSize = dequeSize(d);
    int j = d->beg;

    if (dSize > 0) {
        for (int i = 0; i < dSize; ++i) {
            printf("[%d] = %d\n", j, d->data[j]);
            ++j;
            if (j >= d->cap) j = 0;
        }

        printf("front of deque = %d\n", dequeFront(d));
        printf("back of deque = %d\n", dequeBack(d));

    }
    else
        printf("deque is empty!\n");

}

// prints and empties contents of deque:
void printAndEmptyDeque(struct Deque* d) {

    int dSize = dequeSize(d);

    if (dSize > 0) {
        for (int i = 0; i < dSize; ++i) {
            printf("%d\n", dequeFront(d));
            dequeRemoveFront(d);
        }
    }
    else
        printf("deque is empty!\n");

}
