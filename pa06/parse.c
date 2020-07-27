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
    if (fptr == NULL) {
        return EXIT_FAILURE;
    }

    // how many lines are in the file?
    char ch;
    int numlines = 0;

    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            numlines++;
        }
    }
    rewind(fptr);

    grade_t *gradelist = grade_alloc(numlines);

    // add insert code here

    return gradelist;
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////