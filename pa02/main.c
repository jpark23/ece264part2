//////////////////////////////////////////////////////////////////////////////////////////
//                                         PA02                                         //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h> // to use isalnum() to check for alphanumeric characters
#include <string.h> // to use strlen()

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
    int current;
    int charcount = 0;
    while (1) {
        current = fgetc(fptr);
        
        // check if EOF
        if (feof(fptr)) {
            break;
        }

        if (!isspace(current)) {
            if ( (current != ' ')  && 
	           (current != '\n') && 
	           (current != '\t') &&
	           (current != '\v') &&
	           (current != '\f') &&
	           (current != '\r') ) {
               charcount++;   
            }
        }
    } 
    
    rewind(fptr);
    return charcount; 

}


int is_non_an(int checkchar) { // function to test for alphanumeric characters
    // make an char array that will check for specific cases
    char specs[] = {' ', '.', '?', '!', '"', '/', ','}; // add as necessary
    int alphanum = (checkchar == '-') || isalnum(checkchar); // alphanumeric check

    // inital loop to check for above specific characters
    for (int check = 0; check < 7; check++) {
        if (checkchar == specs[check]) {
            return 1; // meaning that it is NOT an alphanumeric character
        }
    }

    // check if alphanumeric
    if (alphanum) {
        return 0; // the tested character IS alphanumeric
    }

    else
        return 1; // default case is yes it's not alphanumeric

}


 /*
 *  Synopsis        [Count the number of words in a file.]
 *  Return          [Returns the word count.]
 *  Side effects    [None (the initial file cursor position should be the same when
 *                  the function returns!).]
 */
int count_words(FILE *fptr)
{
    int current;
    int wordcount = 0;
    int whitespace = 0; // used to check for whitespace before the actual words
    // sift through the string until we find a character that indicates a word ending
    // end of a word = ' ', '\n'
    
    while (1) {
        current = fgetc(fptr);

        // check if EOF
        if (feof(fptr)) {
            break;
        }

        // figure out a way to check if the file begins with whitespace?
        if (whitespace == 0) {
            whitespace = !isspace(current);
        }

        // actual MEAT - the checking and counting
        while (is_non_an(current) && !feof(fptr) && whitespace) { // do this while the current char is not alphanumeric, not eof, and not whitespace
            current = fgetc(fptr); // get a new check

            if (!is_non_an(current) || feof(fptr)) { // if it is alphanumeric or the last word in the file...
                wordcount++;
                current = 'j'; // exiting the loop to start a new check
            }
        }    
    }

    rewind(fptr);
    return wordcount;  
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
    // comb through the file, and check if the current matches the first char in str
    // if so, enter into a loop the size of the string to compare with the string

    int test;
    int i; // checking which # letter in the string we're at
    int length = strlen(str);
    int count = 0;
    int placeholder;

    while (1) {
        test = fgetc(fptr); // grab the first instance
        i = 0; // resets the check
        placeholder = 1;

        // check for eof
        if (feof(fptr)) {
            break;
        }

        if (test == str[i]) { // if the first character of the string matches the test
            for (i = 1; i < length; i++) {
                test = fgetc(fptr);
                placeholder++; // use this to check if the string is completed
                if (test != str[i]) { // if they dont match stop comparing
                    i = length + 1; // exit the loop
                }
                else if (placeholder == length) {
                    count++;
                    break;
                }
            }
        }
    }
    if (length == 1) {
        printf("\n\nwarning: # of occurences is incorrect due to the string length of 1\n\n");
    }

    return count;
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
    // comb through the file, and check if the current matches the first char in str
    // if so, enter into a loop the size of the string to compare with the string
    rewind(fptr);
    int test;
    int testlower;
    int i; // checking which # letter in the string we're at
    int length = strlen(str);
    int count = 0;
    int placeholder;

    while (1) {
        testlower = fgetc(fptr); // grab the first instance
        test = tolower(testlower);
        i = 0; // resets the check
        placeholder = 1;

        // check for eof
        if (feof(fptr)) {
            break;
        }
        if (test == (tolower(str[i]))) { // if the first character of the string matches the test
            for (i = 1; i < length; i++) {
                testlower = fgetc(fptr);
                test = tolower(testlower);
                placeholder++; // use this to check if the string is completed
                if (test != (tolower(str[i]))) { // if they dont match stop comparing
                    i = length + 1; // exit the loop
                }
                else if (placeholder == length) {
                    count++;
                    break;
                }
            }
        }
    }
    if (length == 1) {
        printf("\n\nwarning: # of occurences is incorrect due to the string length of 1\n\n");
    }

    return count;
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
    printf("Input file '%s' contains %d case insensitive occurrences of the word '%s'.\n", argv[1], ocount2, str2);
#endif

    fclose(ifile);

    return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////