/******************************************************************************
* Description: Implementation file of a Stack using a DynArr
******************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

// adds element to back of array or top of the stack:
void dynArrayPush(struct DynArr* v, TYPE val) {
    
    assert(v != 0);

    addDynArr(v, val);

}

// gets element at the back of the array or top of the stack:
TYPE dynArrayTop(struct DynArr* v) {

    assert(v != 0);

    getDynArr(v, sizeDynArr(v) - 1);

}

// removes last element of the array or top of the stack:
void dynArrayPop(struct DynArr* v) {

    assert(v != 0);

    removeAtDynArr(v, sizeDynArr(v) - 1);

}

// returns 0 if array is not empty or nonzero if array is empty:
int dynArrayIsEmpty(struct DynArr* v) {

    assert(v != 0);

    return (sizeDynArr(v) == 0);

}
