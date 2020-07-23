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
    //int subj_flag = 0; // keep track of which subject we're on

    // allocate a school struct
    school_t *name = school_alloc();

    // read the input file's data into it
    FILE *fptr = fopen(filename, "r");

    // parse the name of the school
    //char* schoolname = malloc(sizeof(filename));
    char care = fgetc(fptr); // gotta initalize it
    int index = 0;
    while ((care = fgetc(fptr)) != EOF) {
        if (care == '/') {
            while (care != '.') {
                care = fgetc(fptr);
                name->name[index++] = care;
            }
        }
    }

    rewind(fptr);
    // how many lines are in the file?
    char ch;
    int numlines = 0;

    while ((ch = fgetc(fptr)) != EOF) {
        if (ch == '\n') {
            numlines++;
        }
    }

    rewind(fptr);
    char* str = malloc(16 * sizeof(char));
    int i = 0;

    while (!feof(fptr)) {
        fgets(str, 16, fptr);
        sscanf(str, "%d,%d,%d,%d", &name->math[i], &name->literature[i], &name->chemistry[i], &name->philosophy[i]);
        i++;
    }

    name->mave = -1;
    name->cave = -1;
    name->lave = -1;
    name->pave = -1;

    // close the file
    fclose(fptr);

    // free the memory?
    //free(name);
    free(str);
    //free(schoolname);

    // return pointer to school struct
    return name;
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////
