//////////////////////////////////////////////////////////////////////////////////////////
//                                       school.c                                       //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "school.h"

school_t *school_alloc(void)
{
    school_t *name = malloc(sizeof(school_t));

    return name;
}

void school_free(school_t *sch)
{
    free(sch); // is this it?

    return;
}

void school_compute_averages(school_t *sch)
{
    // get how many elements are in aray
    int len = sizeof(sch->math) / sizeof(sch->math[0]);

    double math = 0;
    double lit = 0;
    double chem = 0;
    double phil = 0;

    for (int i = 0; i < len; i++) {
        math += sch->math[i];
        lit += sch->literature[i];
        chem += sch->chemistry[i];
        phil += sch->philosophy[i];
    }

    sch->mave = math / len;
    sch->lave = lit / len;
    sch->cave = chem / len;
    sch->pave = phil / len;

    return;
}

void school_print(school_t *sch)
{
    /*
    School: henri quatre
    Math scores: 18, 15, 10, 9, 11
    Literature scores: 4, 5, 7, 18, 13
    Chemistry scores: 17, 15, 20, 7, 10
    Philosophy scores: 4, 10, 5, 19, 11
    Math average: NA
    Literature average: NA
    Chemistry average: NA
    Philosophy average: NA
    */
    printf("\n%s\n", sch->name);

    printf("Math scores: ");
    int len = sizeof(sch->math) / sizeof(sch->math[0]);
    for (int i = 0; i < len; i++) {
        printf("%d ", sch->math[i]);
    } printf("\n");

    printf("Literature scores: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", sch->literature[i]);
    } printf("\n");

    printf("Chemistry scores: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", sch->chemistry[i]);
    } printf("\n");

    printf("Philosophy scores: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", sch->philosophy[i]);
    } printf("\n");

    if (sch->mave != -1) printf("Math average: %.2f\n", sch->mave);
    else printf("Math average: NA\n");
    
    if (sch->lave != -1) printf("Literature average: %.2f\n", sch->lave);
    else printf("Literature average: NA\n");

    if (sch->cave != -1) printf("Chemistry average: %.2f\n", sch->cave);
    else printf("Chemistry average: NA\n");
   
    if (sch->pave != -1) printf("Philosophy average: %.2f\n", sch->pave);
    else printf("Philosophy average: NA\n");
    
    printf("---------------------------------------\n");

    return;
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////
