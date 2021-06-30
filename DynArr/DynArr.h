/******************************************************************************
* Description: Interface file  of a dynamic array in C (s/t C++ vector)
******************************************************************************/

#ifndef TYPE
#define TYPE int
#endif

struct DynArr {

    TYPE *data;     /* pointer to data array */
    int  size;      /* number of elements in array */
    int  cap;       /* capacity of data array */

};

// initialize a dynamic array:
void initDynArr(struct DynArr*, int);

// free the dynamic array:
void freeDynArr(struct DynArr*);

// get size of dynamic array:
int sizeDynArr(struct DynArr*);

// resizes the dynamic array to new capacity passed (doubled):
void _setCapacityDynArr(struct DynArr*, int);

// adds data value passed to dynamic array:
void addDynArr(struct DynArr*, TYPE);

// returns data value at position passed:
TYPE getDynArr(struct DynArr*, int);

// puts data value in position passed:
TYPE putDynArr(struct DynArr*, int, TYPE);

// swaps data values at two positions passed:
void swapDynArr(struct DynArr*, int, int);

// removes element in dynamic array at index passed:
void removeAtDynArr(struct DynArr*, int);

void printDynArr(struct DynArr);
