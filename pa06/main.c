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

	grade_t *head = parse(argv[1]); 

    /*
     * Code that will play around with the grade list to test your functions
     * should go here. Test each function however you see fit. None of this
     * code matters for the grading. Only your functions' code do.
     */
	
	// it dies here
	grade_t *new = grade_alloc(4);
	grades_print_descending(head);
	grade_insert(head, new);
	grades_print_descending(head);

	return EXIT_SUCCESS;
}
//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////