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

    printf("the set contains -1: %d\n", setContains(&myDynArr, -1));
    printf("adding -1 . . .\n");
    addToSet(&myDynArr, -1);
    printf("the set contains -1: %d\n", setContains(&myDynArr, -1));

    printf("the set contains 12: %d\n", setContains(&myDynArr, 12));
    printf("removing 12 . . .\n");
    setRemove(&myDynArr, 12);
    printf("the set contains 12: %d\n", setContains(&myDynArr, 12));
 
    printf("the set contains 40: %d\n", setContains(&myDynArr, 40));
    printf("adding 40 . . .\n");
    printf("array capacity = %d, array size = %d\n", myDynArr.cap, myDynArr.size);
    addToSet(&myDynArr, 40);
    printf("the set contains 40: %d\n", setContains(&myDynArr, 40));
   
    printf("the set contains 20: %d\n", setContains(&myDynArr, 20));
    printf("removing 20 . . .\n");
    setRemove(&myDynArr, 20);
    printf("the set contains 20: %d\n", setContains(&myDynArr, 20));
 
    printDynArr(myDynArr);
    
    freeDynArr(&myDynArr);
}
