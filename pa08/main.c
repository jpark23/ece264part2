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

    init();

    int a = allocate_resource();
    printf("a = 0x%x\n", a);
    int b = allocate_resource();
    printf("b = 0x%x\n", b);
    int c = allocate_resource();
    printf("c = 0x%x\n", c);
    deallocate_resource(b);
    int d = allocate_resource();
    printf("d = 0x%x\n", d);

    // At this point, d should be equal to b!


    return EXIT_SUCCESS;
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////
