//////////////////////////////////////////////////////////////////////////////////////////
//                                        parse.c                                       //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "grade.h"
#include "parse.h"

grade_t *parse(char *filename)
{
    /*
     * Simple parsing function to read grades from an input file.
     * Make this as simple as possible to test each and every function
     * you have to implement. None of the code in this function
     * matters for grading.
     */
    
    // Generates the parse function
    FILE *fptr = fopen(filename, "r");

    int grade;
    fscanf(fptr, "%d", &grade);
    grade_t *head = grade_alloc(grade);

    // add insert code here
    do {
        fscanf(fptr, "%d", &grade);

        if (feof(fptr)) 
            break;

        grade_t *insert = grade_alloc(grade);
        head = grade_insert(head, insert);

    } while (1);

    return head;
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////