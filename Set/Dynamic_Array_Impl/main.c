/******************************************************************************
* Description: Main program for testing
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "Set.h"

int main(int argc, char *argv[]) {

    struct DynArr myDynArr;
    initDynArr(&myDynArr, 1);

    for(int i = 0; i < 12; i++)
        addDynArr(&myDynArr, i * 2);

    printDynArr(myDynArr);

    printf("the set contains 2: %d\n", setContains(&myDynArr, 2));
    printf("the set contains 3: %d\n", setContains(&myDynArr, 3));
    printf("adding 3 . . .\n");
    addToSet(&myDynArr, 3);
    printf("the set contains 3: %d\n", setContains(&myDynArr, 3));
    printf("the set contains 12: %d\n", setContains(&myDynArr, 12));
    printf("removing 12 . . .\n");
    setRemove(&myDynArr, 12);
    printf("the set contains 12: %d\n", setContains(&myDynArr, 12));
    
    printDynArr(myDynArr);
    
    freeDynArr(&myDynArr);
}
