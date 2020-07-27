//////////////////////////////////////////////////////////////////////////////////////////
//                                        main.c                                        //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "grade.h"
#include "parse.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "[ERROR] Usage: %s <input file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	grade_t *grade_list = parse(argv[1]);

    /*
     * Code that will play around with the grade list to test your functions
     * should go here. Test each function however you see fit. None of this
     * code matters for the grading. Only your functions' code do.
     */

	// initalize loop var to first link
	grade_t *ptr = grade_list;

	while (ptr != NULL) {
		grade_list_print(ptr);

		// set loop var to next link
		ptr = ptr->next;
	}

	grade_free(grade_list);

	return EXIT_SUCCESS;
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////