//////////////////////////////////////////////////////////////////////////////////////////
//                                       parse.h                                        //
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef __PARSE_H__
#define __PARSE_H__

#include "school.h"

/*
 *  Synopsis        [Opens and reads the input file to extract the grade information into
 *                  a school structure on the heap.]
 *  Return          [Pointer to the new school structure on the heap.]
 *  Side effects    [None.]
 */
school_t *parse(char *);

#endif
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////