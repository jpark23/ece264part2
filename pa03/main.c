//////////////////////////////////////////////////////////////////////////////////////////
//                                         PA03                                         //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
     * using strchr strcmp, and 
     * 
     * Valid if:
     * begins with a slash character
     * ends with a character other than the slash, or a period
     * the only characters allowed in the path are alphanum, period, hyphens
     *      forward slashes, and underscores
     * no directory name or file name can begin w/ a numeric character or a hyphen
     */ 
    int result = VALID; // valid until proven invalid

    char *period = strstr(filename, ".\0");
    char *slash = strstr(filename, "\\0");

    int alphanum;
    int valid;

    // begins with a slash
    if (filename[0] != '/') {
        result = INVALID;
    }

    // ends with something that's not a slash or a period
    else if (period != NULL && slash != NULL) {
        result = INVALID;
    }

    // only alphanum, period, hyphen, foward slash, or underscores
    int index = 0;
    while (filename[index] > 31 && filename[index] != '\0') {
        alphanum = isalnum(filename[index]);
        valid = (alphanum || 
                filename[index] == '.' || 
                filename[index] == '-' ||
                filename[index] == '/' ||
                filename[index] == '_');
        if (!valid) {
            result = INVALID;
        }
	index++;
    }

    // directory/filename doesnt begin with a numeric or hyphen
    // search for the next /
    // check the first one after and make sure its not a numeric or a hyphen
    int index2 = 0;
    while (filename[index2] > 31 && filename[index2] != '\0') {
        if (filename[index2] == '/') {
            if ( filename[index2 + 1] == '-' ||
                 isdigit(filename[index2 + 1]) ) {
                    result = INVALID;
            }
        }
      index2++;
    }

    return result;
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
    
    // dont forget to check for buffer size

    char newptr[100];
    char newptr2[100];
     	
	if (buffer_size < 100) {
		return CONVERSION_FAIL;
	}

	// find the split point
	int slashcount = 0;
	int breakpoint = 0; // index of 5th /, split between breakpoint and breakpoint+1

	for (int index = 0; index <= 100; index++) {
		if (filename[index] == '/') {
			slashcount++;
			breakpoint = index + 1;	
		}
	}

	// copy the string into the renamed_file
	strcpy(newptr2, filename);
    
    char end[100];
    strcpy(end, filename+breakpoint);

	// cat the correct extension to the filename
	// .c
    if (strstr(end, ".c") != NULL) {
        strcpy(newptr, "c/");
        strcat(newptr, end);
    }

	//.py
    else if (strstr(end, ".py") != NULL) {
        strcpy(newptr, "py/");
        strcat(newptr, end);
    }
	
	// anything else, add misc
    else {
        strcpy(newptr, "misc/");
        strcat(newptr, end);
    }
	
	// add everything to the renamed_filename
    strcpy(newptr2+breakpoint, newptr);
    //strcat(newptr2, newptr); 
    FILE *write = fopen(renamed_filename, "a");
    fputs(newptr2, write);

    fclose(write);

    return 0;
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
    FILE *fptr = fopen(argv[1], "r");
    char readfile[1000];


    while (fgets(readfile, 100, fptr) != NULL) {
        if (check_file_name(readfile)) {
            rename_file_name(argv[2], readfile, 100);
        }
    }

    fclose(fptr);
    return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////
