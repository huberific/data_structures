/******************************************************************************
* Description: Implementation file of a deque using a dynamic array
******************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H
#endif

#ifndef TYPE
#define TYPE int
#endif

struct Deque {

    TYPE *data;     /* pointer to data array */
    int  size;      /* number of elements in array */
    int  cap;       /* capacity of data array */
    int  beg;       /* stores beginning elm # */

};


// initializes a deque using dynamic array:
void dequeInit(struct Deque*, int);

// resizes deque capacity using capacity passed in:
void _dequeSetCapacity(struct Deque*, int);

// returns the number of elements in the deque:
int dequeSize(struct Deque*);

// adds element to front of deque:
void dequeAddFront(struct Deque*, TYPE);

// adds element to back of deque:
void dequeAddBack(struct Deque*, TYPE);

// retruns front element of deque:
TYPE dequeFront(struct Deque*);

// returns back element of deque:
TYPE dequeBack(struct Deque*);

// removes front element of the deque:
void dequeRemoveFront(struct Deque*);

// removes back element of the deque:
void dequeRemoveBack(struct Deque*);

// free dynamic memory:
void dequeFree(struct Deque*);

// prints contents of deque:
void printDeque(struct Deque*);

// prints and empties contents of deque:
void printAndEmptyDeque(struct Deque*);
