//////////////////////////////////////////////////////////////////////////////////////////
//                                       memory.c                                       //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <string.h>

#include "memory.h"
#include "tree.h"

/*
 * I declare and allocate an array in the data section of the program
 * to simulate heap memory. All memory allocations done through the
 * functions in this file will be from this array. The array is
 * declared 'static' such that its declaration is only visible to
 * code within this file (i.e. only functions in this file can
 * access this array using its name 'heap').
 */
static byte heap[HEAP_SIZE];

/*
 * Here, I declare the root of the allocation tree that the
 * memory allocation and free functions manipulate to keep track of
 * allocated blocks. Once again, the 'static' keyword is used here
 * to allow all code from this file to access this tree by name.
 */
static node_t *root;


void memory_init(void)
{
    // Setting all the heap array to zeroes. Absolutely not necessary.
    memset(heap, 0, HEAP_SIZE * sizeof(byte));

    // Initially, the heap array is fully free. At this point,
    // the tree is not needed yet. Hence, we initialize the root
    // to NULL.
    root = NULL;
}


byte *memory_alloc(size_t *size)
{
    /*
     * TODO:
     *
     *
     */
}


void memory_free(byte *address)
{
    /*
     * TODO:
     *
     *
     */
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////