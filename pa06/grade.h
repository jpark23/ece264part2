//////////////////////////////////////////////////////////////////////////////////////////
//                                        grade.h                                       //
//////////////////////////////////////////////////////////////////////////////////////////
#ifndef __GRADE_H__
#define __GRADE_H__

typedef struct grade grade_t;

struct grade {
    int grade;              // Grade out of 20
    struct grade *prev;     // Pointer to previous grade in grade list
    struct grade *next;     // Pointer to next grade in grade list
};

/*
 *  Synopsis        [Allocates and initializes a grade structure on the heap.]
 *  Return          [Pointer to the allocated structure.]
 *  Side effects    [None.]
 */
grade_t *grade_alloc(int);

/*
 *  Synopsis        [Free a grade structure from heap memory.]
 *  Return          [None.]
 *  Side effects    [None.]
 */
void grade_free(grade_t *);

/*
 *  Synopsis        [Insert a grade structure into a grade list while
 *                  maintaining descending order from the head of that
 *                  list.]
 *  Return          [Head of the updated grade list.]
 *  Side effects    [None.]
 */
grade_t *grade_insert(grade_t *, grade_t *);

/*
 *  Synopsis        [Search by grade through the grade list.]
 *  Return          [Pointer to the grade structure if it is in the list.
 *                  NULL otherwise.]
 *  Side effects    [None.]
 */
grade_t *grade_search(grade_t *, int);

/*
 *  Synopsis        [Removes the first grade structure in the grade list.]
 *  Return          [Head of the updated list.]
 *  Side effects    [None.]
 */
grade_t *grade_remove_first(grade_t *);

/*
 *  Synopsis        [Removes the last grade structure in the grade list.]
 *  Return          [Head of the updated list.]
 *  Side effects    [None.]
 */
grade_t *grade_remove_last(grade_t *);

/*
 *  Synopsis        [Removes all grades from the grade list that are
 *                  strictly less than a given threshold.]
 *  Return          [Head of the updated list.]
 *  Side effects    [None.]
 */
grade_t *grade_remove(grade_t *, int);

/*
 *  Synopsis        [Print the grades in a grade list in ascending order.]
 *  Return          [None.]
 *  Side effects    [None.]
 */
void grades_print_ascending(grade_t *);

/*
 *  Synopsis        [Print the grades in a grade list in descending order.]
 *  Return          [None.]
 *  Side effects    [None.]
 */
void grades_print_descending(grade_t *);

void grade_list_print(grade_t *);

#endif
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////