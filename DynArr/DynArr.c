/******************************************************************************
* Description: Implementation of a dynamic array in C (s/t C++ vector)
******************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "DynArr.h"

// initialize a dynamic array:
void initDynArr(struct DynArr *v, int cap) {

    v->data = malloc(sizeof(TYPE) * cap);
    assert(v->data != 0);

    v->size = 0;
    v->cap = cap;

}

// free the dynamic array:
void freeDynArr(struct DynArr *v) {

    if(v->data != 0) {
        free(v->data);  /* free dyn memory on the heap */
        v->data = 0;    /* data pointer points to NULL */
    }

    v->size = 0;
    v->cap = 0;

}

// get size of dynamic array:
int sizeDynArr(struct DynArr *v) {

    return v->size;

}

// resizes the dynamic array to new capacity passed (doubled):
void _setCapacityDynArr(struct DynArr *v, int newCap) {

    /* create new dyn array of size passed */
    TYPE* newDynArr = malloc(sizeof(TYPE) * newCap);
    assert(newDynArr != 0);

    for(int i = 0; i < v->size; i++)
        newDynArr[i] = v->data[i];

    /* free prev data array mem location */
    free(v->data);

    v->data = newDynArr;
    v->cap = newCap;

}

// adds data value passed to dynamic array:
void addDynArr(struct DynArr *v, TYPE val) {

    /* check if resize is necessary */
    if(v->size == v->cap)
        _setCapacityDynArr(v, v->cap * 2);

    v->data[v->size] = val;
    v->size++;

}

// returns data value at position passed:
TYPE getDynArr(struct DynArr *da, int position) {

    assert(position >= 0);
    assert(da->size > 0 && position < da->size);

    return da->data[position];

}

// puts data value in position passed:
TYPE putDynArr(struct DynArr *da, int position, TYPE value) {

    assert(position >= 0);
    assert(da->size > 0 && position < da->size);

    da->data[position] = value;

}

// swaps data values at two positions passed:
void swapDynArr(struct DynArr *da, int i, int j) {

    assert(da->size > 0);
    assert(i >= 0 && j >= 0);
    assert(i < da->size && j < da->size);

    TYPE temp = da->data[i];
    da->data[i] = da->data[j];
    da->data[j] = temp;

}

// removes element in dynamic array at index passed:
void removeAtDynArr(struct DynArr *da, int index) {

    assert(da->size > 0);
    assert(index >= 0 && index < da->size);

    for(int i = index + 1; i < da->size; i++)
        da->data[i - 1] = da->data[i];

    da->size--;

}

// prints contents of dynamic array:
void printDynArr(struct DynArr v) {

    if(v.size > 0)
        for(int i = 0; i < v.size; i++)
            printf("%d\n", v.data[i]);
    else
        printf("dyn array empty!\n");

}
