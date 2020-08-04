//////////////////////////////////////////////////////////////////////////////////////////
//                                     allocation.h                                     //
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef __ALLOCATION_H__
#define __ALLOCATION_H__

/*
 * Here is the allocate_resource() function. All that function
 * does is navigate the bitmap in order to find an available
 * resource in the bank (do not navigate the bank itself directly!
 * That's cheating.) The function should start with the first bit
 * in the bitmap and go over every bit sequentially until it finds
 * a bit set to 1, in which case it has found an available resource
 * to allocate. That bit should then be set to 0 and the function
 * should return the corresponding index in the ank array. If the
 * function cannot find an available resource, it should terminate
 * the program on an error message.
 */
int allocate_resource(void);

/*
 * The deallocate_resource() function should navigate the bitmap to
 * reset the bit of a resource to 1 to indicate that it is
 * available again. The argument is the index of the resource to
 * de-allocate in the bank array. This function should check the
 * validity of the argument before attempting to de-allocate the
 * resource.
 */
void deallocate_resource(int);

#endif
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////