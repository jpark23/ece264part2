//////////////////////////////////////////////////////////////////////////////////////////
//                                         PA02                                         //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Comment out the next line if you do not wish to do the extra credit
#define EXTRA_CREDIT


/*
 *  Synopsis        [Count the number of characters in a file.]
 *  Return          [Returns the character count.]
 *  Side effects    [None (the initial file cursor position should be the same when
 *                  the function returns!).]
 */
int count_chars(FILE *fptr)
{
    // TODO
}


/*
 *  Synopsis        [Count the number of words in a file.]
 *  Return          [Returns the word count.]
 *  Side effects    [None (the initial file cursor position should be the same when
 *                  the function returns!).]
 */
int count_words(FILE *fptr)
{
    // TODO
}


/*
 *  Synopsis        [Count the number of case sensitive occurrences of a given word in
 *                  a file. Ignore all comments. You can assume that the str
 *                  argument ends with the null terminating character.]
 *  Return          [Returns the occurrence count.]
 *  Side effects    [None (the initial file cursor position should be the same when
 *                  the function returns!).]
 */
int count_case_sensitive_occurrences(FILE *fptr, char const *str)
{
    // TODO
}


/*
 *  Note:           This function is required for the EXTRA CREDIT.
 *
 *  Synopsis        [Count the number of case insensitive occurrences of a given
 *                  word in a file. Ignore all comments. You can assume that the str
 *                  argument ends with the null terminating character.]
 *  Return          [Returns the occurrence count.]
 *  Side effects    [None (the initial file cursor position should be the same when
 *                  the function returns!).]
 */
int count_case_insensitive_occurrences(FILE *fptr, char const *str)
{
    // TODO
}


int main(int argc, char **argv)
{
    // Check for the user inputs to the program
    if (argc != 2) {
        fprintf(stderr, "[ERROR] Usage: %s <input file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the input file in read-only mode
    FILE *ifile = fopen(argv[1], "r");
    if (ifile == NULL) {
        fprintf(stderr, "[ERROR] %s:%d: %s\n", __FILE__, __LINE__, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Count characters
    int ccount = count_chars(ifile);
    printf("Input file '%s' contains %d characters.\n", argv[1], ccount);

    // Count words
    int wcount = count_words(ifile);
    printf("Input file '%s' contains %d words.\n", argv[1], wcount);

    // Count case sensitive occurrences of a string
    char *str = "The";
    int ocount = count_case_sensitive_occurrences(ifile, str);
    printf("Input file '%s' contains %d case sensitive occurrences of the word '%s'.\n", argv[1], ocount, str);

    // EXTRA CREDIT: count case insensitive occurrences of a string
#ifdef EXTRA_CREDIT
    char *str2 = "The";
    int ocount2 = count_case_insensitive_occurrences(ifile, str2);
    printf("Input file '%s' contains %d case insensitive occurrences of the word '%s'.\n", argv[1], ocount, str);
#endif

    fclose(ifile);

    return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////
