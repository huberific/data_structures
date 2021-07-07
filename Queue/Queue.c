/*******************************************************************************
* Author:       Aaron Huber
* Description:  Implementation file of a Queue using a Linked List w/ Sentinel
*******************************************************************************/

#include "Queue.h"

/* initializes queue and sentinel */
void initQueue(struct Queue* q) {

    assert(q != 0);

    /* create sentinel (ensures no seg fault in empty list) */
    /* sentinel never gets removed */
    struct Link* sentinel = (struct Link*)malloc(sizeof(struct Link));
    assert(sentinel != 0);
    sentinel->next = NULL;

    /* empty queue front and back point to sentinel */
    q->front = q->back = sentinel;

}

/* adds item to back of queue */
void push(struct Queue* q, TYPE newVal) {

    assert(q != 0);

    /* create new link */
    struct Link* newLink = (struct Link*)malloc(sizeof(struct Link));
    assert(newLink != 0);

    /* set values of new link */
    newLink->val = newVal;
    newLink->next = q->back->next;

    q->back->next = newLink;
    q->back = newLink;

}

/* returns front of queue value */
TYPE front(struct Queue* q) {

    assert(q != 0);

    if (!isEmpty(q))
        return q->front->next->val;

}

/* removes front of queue */
void pop(struct Queue* q) {

    assert(q != 0);

    if (!isEmpty(q)) {
        struct Link* temp = q->front->next;
        q->front->next = q->front->next->next;
        free(temp);
        temp = NULL;
    }

    if (q->front->next == NULL)
        q->back = q->front;

}

/* returns 0 if queue is not empty, else non-zero */
int isEmpty(struct Queue* q) {

    assert(q != 0);

    return(q->front == q->back);

}

/* print contents of queue */
void printQueue(struct Queue* q) {

    assert(q != 0);

    if (isEmpty(q)) {
        printf("queue is empty\n");
        return;
    }

    struct Link* ptr = q->front->next;

    printf("queue front = %d\nqueue contents:\n", front(q));
    
    while (ptr != NULL) {
        printf("%d ", ptr->val);
        ptr = ptr->next;
    }

    printf("\n");

}

/* clears and deletes queue */
void deleteQueue(struct Queue* q) {

    assert(q != 0);

    while (!isEmpty(q))
        pop(q);

    /* free sentinel memory */
    free(q->front);
    q->front = NULL;
    q->back = NULL;

}
