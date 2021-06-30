/******************************************************************************
* Description: Main program for testing
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "DynArr.h"

int main(int argc, char *argv[]) {

    struct DynArr myDynArr;
    initDynArr(&myDynArr, 1);

    for(int i = 0; i < 12; i++){
        addDynArr(&myDynArr, 11 * i);
        printf("array size = %d\n", myDynArr.cap);
    }

    printDynArr(myDynArr);
    
    for(int i = 0; i < 12; i++)
        removeAtDynArr(&myDynArr, 0);

    printDynArr(myDynArr);

    freeDynArr(&myDynArr);
}
