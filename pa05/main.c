//////////////////////////////////////////////////////////////////////////////////////////
//                                        main.c                                        //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "school.h"
#include "parse.h"

typedef struct avg_comp average;
struct avg_comp {
    char name[NAME_SIZE]; // name
    double avg; // average
};

int comp(average *a, average *b)
{
    double avg1 = a->avg;
    double avg2 = b->avg;

    double pass = avg1 - avg2;
    
    return pass;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "[ERROR] Usage: %s <input file 1> <input file 2> ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    school_t *sch;

    // create array of structs
    average* compare[argc - 1];

    for (int i = 1; i < argc; i++) {
        sch = parse(argv[i]);
        school_compute_averages(sch);
        school_print(sch);
        compare[i - 1]->avg = (sch->mave + sch->lave + sch->cave + sch->pave) / 4;
        strcpy(compare[i - 1]->name, sch->name);
    }

    int len = sizeof(compare) / sizeof(struct school);
    qsort(compare, len, sizeof(struct school *), comp);
    
    return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////