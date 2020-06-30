//////////////////////////////////////////////////////////////////////////////////////////
//                                         PA03                                         //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>

/*
 * Some #defines you might find useful.
 */
#define VALID   1
#define INVALID 0

#define CONVERSION_SUCCESS  1
#define CONVERSION_FAIL     0

/*
 *  Synopsis        [Check that a file path is valid.]
 *  Return          [Returns VALID on if the path is valid, INVALID otherwise.]
 *  Side effects    [None.]
 */
int check_file_name(const char *filename)
{
    /*
     * You could implement a function here that checks whether a
     * given filename is a valid filename according to the
     * specifications provided in the assignment document.
     */
}

/*
 *  Synopsis        [Rename a file path.]
 *  Return          [Returns CONVERSION_SUCCESS on success, CONVERSION_FAIL otherwise.]
 *  Side effects    [None.]
 */
int rename_file_name(char *renamed_filename, const char *filename, unsigned int buffer_size)
{
    /*
     * You could implement this function to perform the conversion
     * of a given filename to the new, desired filename according
     * to the specifications in the assignment document. Note that,
     * if you wanted to use this function template, the destination
     * buffer address is passed as an argument. The size of the
     * buffer is also passed as an argument. If the destination
     * buffer is not large enough, we may want to return
     * CONVERSION_FAIL. There are other ways of doing this without
     * passing the destination buffer address as an argument. However,
     * since we have not covered them yet, I recommend this way.
     */
}


int main(int argc, char **argv)
{
     // Check argument count
    if (argc != 3)
    {
        fprintf(stderr, "[ERROR] Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /*
     * In this part of main(), you could open the input file, read
     * the file names and process them in a loop.
     */

    return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////
