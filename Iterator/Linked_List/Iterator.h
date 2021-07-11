/*******************************************************************************
* Author:      Aaron Huber
* Description: Interface file of Iterator of Doubly Linked List (deque)
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../../Deque/Linked_List_Impl/Deque.h"

#ifndef TYPE
#define TYPE int
#endif

struct Iterator {
    
    struct Deque* d;
    struct DLink* currLink;

};

/* initiliazes iterator of a deque */
void initIterator(struct Deque*, struct Iterator*);

/* boolean check to see if there is a next link */
int hasNext(struct Iterator*);

/* returns value of next link */
TYPE next(struct Iterator*);

/* removes current link of iterator */
void removeItr(struct Iterator*);
