//////////////////////////////////////////////////////////////////////////////////////////
//                                        tree.h                                        //
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef __TREE_H__
#define __TREE_H__

#include <stdlib.h>

#include "memory.h"

typedef struct node node_t;

struct node {
    byte *block_start_address;
    size_t largest_block_left;
    size_t largest_block_right;
    struct node *left;
    struct node *right;
};

/*
 * TODO: Your functions implementing the allocation tree
 * go here.
 */

#endif
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////