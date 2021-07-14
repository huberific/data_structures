/******************************************************************************
* Description: Interface file of a set using a dynamic array
******************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../DynArr/DynArr.h"

#ifndef TYPE
#define TYPE int
#endif

/* returns index of value passed or -1 if value not found */
int _binarySearch(TYPE*, int, TYPE);

/* searches set for value and returns index */
int setSearch(struct DynArr*, TYPE);

/* adds element with value passed */
void addToSet(struct DynArr*, TYPE);

/* boolean check to see if set contains element passed */
int setContains(struct DynArr*, TYPE);

/* removes element with value passed */
int setRemove(struct DynArr*, TYPE);
