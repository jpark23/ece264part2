//////////////////////////////////////////////////////////////////////////////////////////
//                                        main.h                                        //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

#include "resource.h"
#include "allocation.h"

/*
 * INTRODUCTION
 *
 * This is PA08, which will only count for extra credit.
 * This assignment is about bit-wise operations and bitmaps.
 * You'll pretty much be copying-pasting the code from lecture
 * to complete this assignment. The idea is to incentivize you
 * to look over these lectures in preparation for the final exam.
 */
int main(int argc, char *argv[])
{
    /*
     * Test your allocation and de-allocation functions here
     * by simply calling them in different sequences.
     */
    int a = allocate_resource();
    int b = allocate_resource();
    int c = allocate_resource();
    deallocate_resource(b);
    int d = allocate_resource();

    // At this point, d should be equal to b!


    return EXIT_SUCCESS;
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////