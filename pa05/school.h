//////////////////////////////////////////////////////////////////////////////////////////
//                                       school.h                                       //
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef __SCHOOL_H__
#define __SCHOOL_H__

#define NAME_SIZE       256
#define NUM_STUDENTS    5

typedef struct school school_t;

struct school {
    char name[NAME_SIZE];           // School's name

    int math[NUM_STUDENTS];         // Students' math grades as read from the input file
    int literature[NUM_STUDENTS];   // etc.
    int chemistry[NUM_STUDENTS];
    int philosophy[NUM_STUDENTS];

    double mave, lave, cave, pave;  // Average grades by subject
};

/*
 *  Synopsis        [Allocates a school structure on the heap.]
 *  Return          [Pointer to the allocated structure.]
 *  Side effects    [None.]
 */
school_t *school_alloc(void);

/*
 *  Synopsis        [Frees the allocated school structure from the heap.]
 *  Return          [None.]
 *  Side effects    [None.]
 */
void school_free(school_t *);

/*
 *  Synopsis        [Computes a school's average grades.]
 *  Return          [None.]
 *  Side effects    [None.]
 */
void school_compute_averages(school_t *);

/*
 *  Synopsis        [Prints the information related to a school to stdout.]
 *  Return          [None.]
 *  Side effects    [None.]
 */
void school_print(school_t *);

#endif
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////