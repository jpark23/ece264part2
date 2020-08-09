//////////////////////////////////////////////////////////////////////////////////////////
//                                     allocation.c                                     //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

#include "allocation.h"
#include "resource.h"

#define IN_USE 1
#define AVAIL 0

/*
 * This is the bank of resources. It represents all the resources
 * we have available to us. The allocate_resource() and
 * deallocate_resource() functions below manage this array to make
 * sure no resource is going to waste.
 */
static resource_t bank[100]; // allocate a bank of 100 links

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

void init(void) 
{
    for (int ind = 0; ind < 4; ind++) {
        bitmap[ind] = 0xffffffff;
    }
}

int allocate_resource(void)
{
    /* Here is the allocate_resource() function. All that function
    does is navigate the bitmap in order to find an available
    resource in the bank (do not navigate the bank itself directly! 
    That's cheating.) The function should start with the first bit
    in the bitmap and go over every bit sequentially until it finds
    a bit set to 1, in which case it has found an available resource
    to allocate. That bit should then be set to 0 and the function
    should return the corresponding index in the bank array. If the
    function cannot find an available resource, it should terminate
    the program on an error message. */

    int i = 0;

    // while bitnap entry is all zeros, keep checking
    while (!bitmap[i]) {
        i++;
    }

    // mask initially pointing to first bit in bitmap i
    // needs to be unsigned?
    int mask = 0x80000000;
    int count = 0;
    while (!(bitmap[i] & mask)) {
        mask = mask >> 1;
        count++;
    }
  
    int index = 32 * 1 + count;

    bitmap[i] = bitmap[i] ^ mask;

    return index;
}

void deallocate_resource(int index)
{
    int i = index / 32;
    int j = index % 32;

    int mask = 0x80000000;
    for (int x = 0; x < j; x++) {
        mask = mask >> 1;
    }

    bitmap[i] = bitmap[i] ^ mask;

}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////
