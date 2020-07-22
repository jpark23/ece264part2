//////////////////////////////////////////////////////////////////////////////////////////
//                                        main.c                                        //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "school.h"
#include "parse.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "[ERROR] Usage: %s <input file 1> <input file 2> ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // TODO
    parse(argv[1]);
    //parse(argv[1]);

    return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////