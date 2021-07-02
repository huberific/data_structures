/******************************************************************************
* Description: Interface file of a Stack using a DynArr
******************************************************************************/

#include "../DynArr/DynArr.h"

// adds element to back of array or top of the stack:
void dynArrayPush (struct DynArr*, TYPE);

// gets element at the back of the array or top of the stack:
TYPE dynArrayTop(struct DynArr*);

// removes last element of the array or top of the stack:
void dynArrayPop(struct DynArr*);

// returns 0 if array is not empty or nonzero if array is empty:
int dynArrayIsEmpty(struct DynArr*);
