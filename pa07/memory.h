//////////////////////////////////////////////////////////////////////////////////////////
//                                       memory.h                                       //
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef __MEMORY_H__
#define __MEMORY_H__

/*
 * Define the size of the heap memory to be 1MiB.
 */
#define HEAP_SIZE 1048576


/*
 * The 'unsigned char' built-in data type will be used to represent
 * a byte of memory (true on virtually all computer systems). I use a
 * typedef here to simplify the code later on.
 */
typedef unsigned char byte;


/*
 *  Synopsis        [Initializes the heap array to all zeroes and the
 *                  allocation tree, maintained by the memory_alloc()
 *                  and memory_free() functions. This function should
 *                  be called only once in main() at the very beginning.]
 *  Return          [None.]
 *  Side effects    [None.]
 */
void memory_init(void);


/*
 *  Synopsis        [Finds a suitable block of memory from the heap
 *                  array defined above according to the buddy method
 *                  (discussed in lecture and the assignment document).]
 *  Return          [If the allocation succeeds, a pointer to the first
 *                  byte in the allocated block of memory from the heap
 *                  array. If the allocation fails, returns NULL.]
 *  Side effects    [The allocation tree is modified to keep track of any
 *                  allocation made from the heap array.]
 */
byte *memory_alloc(size_t );


/*
 *  Synopsis        [If the provided byte address is valid, frees the
 *                  associated memory block by modifying the allocation
 *                  tree.]
 *  Return          [None. The function should terminate the program with
 *                  an error message if the provided byte address is
 *                  invalid.]
 *  Side effects    [None.]
 */
void memory_free(byte *);

#endif
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////
