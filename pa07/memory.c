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

byte *find_block(size_t size, node_t *tn);

void memory_init(void)
{
    // Setting all the heap array to zeroes. Absolutely not necessary.
    memset(heap, 0, HEAP_SIZE * sizeof(byte));

    // Initially, the heap array is fully free. At this point,
    // the tree is not needed yet. Hence, we initialize the root
    // to NULL.
    root = NULL;
}


byte *memory_alloc(size_t size)
{
	// Compute most suitable block size
	int order = ceil(log(size) / log(2));
	size_t best = pow(2, order);

	return find_block(best, root);	
}

byte *find_block(size_t size, node_t *tn)
{
	/* See 53:00 for implementation */
	if (size <= tn->largest_block_left) {
		if (tn->left == NULL) {
			if (tn->largest_block_left == size) {
				tn->largest_block_left = 0;
				return tn->block_start_address; 
			} else {
				node_t *new = node_alloc();
				/* THE BELOW LOGIC SHOULD BE A PART OF NODE_ALLOC()[?]*/
				new->block_start_address = tn->block_start_address;
				new->largest_block_left = tn->largest_block_left / 2;
				new->largest_block_right = tn->largest_block_right / 2;
				new->left = NULL;
				new->right = NULL;
				tn->left = new;
				byte *addr = find_block(size, tn->left);
				size_t max = tn->left->largest_block_left > tn->left->largest_block_right ? tn->left->largest_block_left : tn->left->largest_block_right;
				tn->largest_block_left = max;
				return addr;
				
			}

		} else {
			// theres a node, theres a split
			byte *addr = find_block(size, tn->left);
			// update largest_block_left
			size_t max = tn->left->largest_block_left > tn->left->largest_block_right ? tn->left->largest_block_left : tn->left->largest_block_right;
			tn->largest_block_left = max;
			return addr;
		}
	}	

	else if (size <= tn->largest_block_right) {
		if (tn->left == NULL) {
			if (tn->largest_block_left == size) {
				tn->largest_block_left = 0;
				return tn->block_start_address + (size / 2); // this line is different for the right	- CHANGE THIS ONE
			} else {
				node_t *new = node_alloc();
				/* THE BELOW LOGIC SHOULD BE A PART OF NODE_ALLOC()*/
				new->block_start_address = tn->block_start_address + (size / 2); // different for right - CHANGE THIS ONE
				new->largest_block_left = tn->largest_block_left / 2;
				new->largest_block_right = tn->largest_block_right / 2;
				new->left = NULL;
				new->right = NULL;
				tn->left = new;
				byte *addr = find_block(size, tn->left);
				size_t max = tn->left->largest_block_left > tn->left->largest_block_right ? tn->left->largest_block_left : tn->left->largest_block_right;
				tn->largest_block_left = max;
				return addr;
				
			}

		} else {
			// theres a node, theres a split
			byte *addr = find_block(size, tn->left);
			// update largest_block_left
			size_t max = tn->left->largest_block_left > tn->left->largest_block_right ? tn->left->largest_block_left : tn->left->largest_block_right;
			tn->largest_block_left = max;
			return addr;
		}
	}

	return NULL;
}

void memory_free(byte *address)
{
    /*
     * TODO:
     * base case where tn->largest_block_left back to original block size or something like that
     * probably recursive
     * which block does the block address connect to?
     * based on the address, the block will be on the left or the right
     * 	if not found, the address is invalid -> terminate
     * find the block to free, free the block (largest_block_left/right to some value)
     *
     * check if two nodes are buddies
     * 	look at node that represents split
     * 	if tn left and tn right is null
     * 		on the left and right there are blocks, you can merge them
     * 		to remove the split, remove the node
     *
     */
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////
