/******************************************************************************
* Description: Interface file of a Stack using a DynArr
******************************************************************************/

#include "../DynArr/DynArr.h"

void dynArrayPush (struct DynArr*, TYPE);

TYPE dynArrayTop(struct DynArr*);

void dynArrayPop(struct DynArr*);

int dynArrayIsEmpty(struct DynArr*);
