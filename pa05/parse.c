//////////////////////////////////////////////////////////////////////////////////////////
//                                       parse.c                                        //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "school.h"
#include "parse.h"

/*
struct school {
char name [ NAME_SIZE ]; // School ’s name

int math [ NUM_STUDENTS ]; // Students ’ math grades as read from the input file
int literature [ NUM_STUDENTS ]; // etc .
int chemistry [ NUM_STUDENTS ];
int philosophy [ NUM_STUDENTS ];

double mave , lave , cave , pave ; // Average grades by subject
};
*/

school_t *parse(char *filename)
{
    int subj_flag = 0; // keep track of which subject we're on

    // allocate a school struct
    school_t *name = malloc(sizeof(school_t));

    // read the input file's data into it
    FILE *fptr = fopen(filename, "r");

    // how many lines are in the file?
    char ch;
    int numlines = 0;

    while((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            numlines++;
        }
    }

    // allocate 4 subject arrays
    int math_arr, lit_arr, chem_arr, phil_arr = malloc(numlines * sizeof(int));

    while (!feof(fptr)) {
        for (int i = 0; i <= 4) {
            
        }
    }

    // close the file
    // free the memory
    // return pointer to school struct
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////