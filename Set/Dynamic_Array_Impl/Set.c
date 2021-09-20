/******************************************************************************
* Description: Implementation file of a set using a dynamic array
******************************************************************************/

#include "Set.h"

/* returns index of value passed or which index the value should be placed */
int _binarySearch(TYPE* arr, int size, TYPE val) {

    assert(arr != 0);

    int low = 0;
    int high = size;
    int mid;
    
    while(low < high) {

        mid = (low + high) / 2;

        if(arr[mid] < val)
            low = mid + 1;

        else
            high = mid;

    }
            
    return low;   

}

/* searches set for value and returns index */
int setSearch(struct DynArr* d, TYPE val) {

    assert(d != 0);

    return _binarySearch(d->data, d->size, val);

}

/* adds element with value passed */
void addToSet(struct DynArr* d, TYPE val) {

    assert(d != 0);

    /* ensure there is space for data to go */
    if(d->size >= d->cap)
        _setCapacityDynArr(d, d->cap * 2);

    /* search for index containing value already */
    int idx = setSearch(d, val);

    /* if value already exists, ignore and return */
    if(d->data[idx] == val)
        return;

    /* shift current index values to the right to make room */
    for(int ptr = d->size; ptr > idx; --ptr)
        d->data[ptr] = d->data[ptr - 1];

    /* place value at index returned from binary search */
    putDynArr(d, idx, val);

    d->size++;

}

/* boolean check to see if set contains element passed */
int setContains(struct DynArr* d, TYPE val) {

    assert(d != 0);

    int idx = setSearch(d, val);

    return (idx >= 0 && idx < d->size && d->data[idx] == val);

}

/* removes element with value passed */
int setRemove(struct DynArr* d, TYPE val) {

    assert(d != 0);

    int idx = setSearch(d, val);

    if(idx >= 0 && idx < d->size && d->data[idx] == val)
        removeAtDynArr(d, idx);

}
