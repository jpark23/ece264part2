//////////////////////////////////////////////////////////////////////////////////////////
//                                        grade.c                                       //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "grade.h"

grade_t *grade_alloc(int grad)
{
    /* allocates and initalizes a grade structure on the heap
    returns a pointer to the allocated structure */

    grade_t *gradelist = malloc(sizeof(grade_t));

	gradelist->grade = grad;

    gradelist->prev = NULL;
    gradelist->next = NULL;

    // error check?

    return gradelist;
}

void grade_free(grade_t *something)
{
    /* frees the memory associated with a grade structure from heap memory
    No return. No print. */

    free(something);
	something = NULL;
}

grade_t *grade_insert(grade_t *head, grade_t *new)
{
    /*
    * insert a grade structure into a grade list such that the list's descending order
    * starting from the list head is maintained. You can assume that the linked list
    * provided to the function is in descending order. The function should return the
    * updated list's head.
    * No return. No print.
    */

    //new->next = head;
    //head = new;

    new->prev = head;
    head = new->next; // or head->next

    return head;
}

grade_t *grade_search(grade_t *head, int searchfor)
{
    /*
    * Function should search for a grade structure in the grade linked list based on a 
    * given grade out of 20. It should return a pointer to the desired grade structure.
    * (DO NOT REMOVE THE SAID STRUCTURE FROM THE LIST) If the desired grade is not 
    * present, the function should return NULL.
    * No print.
    */

    /*
    struct grade {
    int grade;              // Grade out of 20
    struct grade *prev;     // Pointer to previous grade in grade list
    struct grade *next;     // Pointer to next grade in grade list */

	grade_t *ptr = head;

    while (ptr->next != head) { 
        if (ptr->grade == searchfor) {
            	return ptr;
        }
        if (ptr->next != NULL) {
            	ptr = ptr->next;
        	} else return NULL;
    }
	
	ptr = ptr->next; // advance to the final link
	if (ptr->grade == searchfor) {
		return ptr;
	} else return NULL;
}

grade_t *grade_remove_first(grade_t *head) 
{
    /*
    * This function should remove the first grade structure, the one pointed to by the
    * list head, from the grade list. It should return the updated list's head.
    * No print.
    */

    // loop through the list until we find the one to eliminate? no cause we want the first one
    grade_t *first = head; // temporary storage
    head->prev->next = head->next;
    head->next->prev = head->prev;

    first = head->next;

    grade_free(head);
    
    return first;
}

grade_t *grade_remove_last(grade_t *head)
{
    /*
    * This function should remove the last grade structure from the grade list. It should
    * return the updated list's head.
    * No print.
    */

    // if it was next to remove the first one, than prev should be the last one

    grade_t *temp = head->prev;

    head->prev->prev->next = head;
    head->prev = head->prev->prev;

    grade_free(temp);

    return head;
}

grade_t *grade_remove(grade_t *head, int cap) // EXTRA CREDIT
{
    /*
    * This function should remove all grades from the grade list that are strictly less than
    * a given grade out of 20, passed as parameter to the function. It should return the 
    * updated list's head.
    * No print.
    */

    grade_t *remove;

    for (int i = 0; i < cap; i++) {
        remove = grade_search(head, i);
        if (remove != NULL) {
            grade_remove_first(remove); // cuz this sets the "head" to the one to be removed
        }
    }

    // do I need to adjust the head before returning?

    return head;
}

void grades_print_ascending(grade_t *head)
{
    /*
    * The function should print to stdout the grades in the grade list that are strictly less
    * than a given grade out of 20, passed as parameter to the function. It should return the
    * list's head.
    * No print.
    * 
    * ex: grade list: 17, 10, 5
    * prints: 5, 10, 17
    */

    grade_t *ptr = head->prev;

    while (ptr->prev != head->prev) {
        printf("%d ", ptr->grade);
    }

    ptr = ptr->prev;
    printf("%d ", ptr->grade);
    printf("\n");

    return;
}

void grades_print_descending(grade_t *head)
{
    /*
    * The function should print to stdout the grades in the grade list in descending order.
    * No return.
    * 
    * ex: grade list: 17, 10, 5
    *     prints: 17, 10, 5
    */
   
    grade_t *ptr = head;
    
    while (ptr->next != head) {
        printf("%d ", ptr->grade);
    }

    ptr = ptr->next;
    printf("%d ", ptr->grade);
    printf("\n");

    return;
}

void grade_list_print(grade_t *head)
{
    grade_t *ptr = head->prev;

    while (ptr->prev != head->prev) {
        printf("%d ", ptr->grade);
    }

    ptr = ptr->prev;
    printf("%d ", ptr->grade);
    printf("\n");

    return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////
