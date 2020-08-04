//////////////////////////////////////////////////////////////////////////////////////////
//                                     allocation.c                                     //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

#include "allocation.h"
#include "resource.h"

/*
 * This is the bank of resources. It represents all the resources
 * we have available to us. The allocate_resource() and
 * deallocate_resource() functions below manage this array to make
 * sure no resource is going to waste.
 */
static resource_t bank[100];

/*
 * We never want to have to navigate the resource bank directly to
 * find one that is available. That's way too much data movement.
 * Instead, we use a bitmap, which gives us a snapshot of which
 * resources are available and which are not. Remember that each bit
 * in the bitmap represents the availability of one resource in the
 * bank. Hence, the 5th bit in this bitmap tells whether the fifth
 * resource (index number 4) in the bank is available or not. Note
 * that for the bitmap, we are using integers. Since an integer is
 * going to be 32 bits on the ecegrid machines, we need 4 integers
 * to keep track of 100 resources.
 */
static int bitmap[4];

int allocate_resource(void)
{
    // TODO
}

void deallocate_resource(int index)
{
    // TODO
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////