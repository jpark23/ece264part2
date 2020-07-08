//////////////////////////////////////////////////////////////////////////////////////////
//                                         PA04                                         //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

// You can use these constant in your find_path function.
#define PRESENT 1
#define ABSENT  0

// define the new function
int read_char(FILE *fptr);

/*
 *  Synopsis        [Build the adjacency matrix representation of a graph
 *                  from a valid edge list.]
 *  Return          [Returns a pointer to the adjacency matrix on the heap.]
 *  Side effects    [The n argument is populated with the number of vertices
 *                  in the input graph.]
 */
int **get_adj_mat(FILE *fptr, int *n)
{
    // don't forget to refer to *n, not n
    // we're returning two things, but explicity return a pointer the the adj matrix
    // read twice, but dont need to open twice

    // allocate adjacency matrix with size from the edge list
    // how many nodes? if the size is n, adj needs to be n by n

    // reading loop one, how many nodes in the graph?
    int ch;
    int biggest = 0;
    while (1) {
        ch = read_char(fptr); // read first character on the line
        //printf("ch = %d\n", ch);

        if(feof(fptr)) {
            break; // exits the loop if EOF
        }

        if (ch == '#') { // can't use this line, need to bypass
            while (ch != '\n' && !feof(fptr)) {
                ch = read_char(fptr);
            }
        }

        else {
            // go to the beginning of the line
            ungetc(ch, fptr);

            // grab the numbers from the file
            int src;
            int dst;
            char ssrc[128];
            char sdst[128];
            fscanf(fptr, "%s %s", ssrc, sdst);

            char *endptr = NULL;
            src = strtol(ssrc, &endptr, 10);
            endptr = NULL;
            dst = strtol(sdst, &endptr, 10);

            // figure out which one is biggest
            if (src > biggest) {
                biggest = src;
            } 
            else if (dst > biggest) {
                biggest = dst;
            }
        }
    }
    *n = biggest;
    printf("biggest = %d\n", biggest);
    // allocate the matrix
    int *adj[*n]; // = malloc(*n * sizeof(int)); 
    for (int i = 0; i < *n; i++) {
        adj[i] = malloc(*n * sizeof(int));
    }
    
    // initialize all entries to 0
    int row;
    int col;
    for (row = 0; row < *n; row++) {
        for (col = 0; col < *n; col++) {
            adj[row][col] = 0;
        }
    }

    rewind(fptr);
    // once read an edge, replace entry from 0 to 1
    int ch2;
    while (1) {
        ch2 = read_char(fptr); // read first character on the line
        //printf("ch = %d\n", ch);

        if(feof(fptr)) {
            break; // exits the loop if EOF
        }

        if (ch2 == '#') { // can't use this line, need to bypass
            while (ch2 != '\n' && !feof(fptr)) {
                ch2 = read_char(fptr);
            }
        }

        else {
            ungetc(ch2, fptr); // back to beginning of the line
            int src2;
            int dst2;

            // character buffers
            char ssrc2[128];
            char sdst2[128];
            fscanf(fptr, "%s %s", ssrc2, sdst2);

            // convert the strings to ints
            char *endptr;
            endptr = NULL;
            src2 = strtol(ssrc2, &endptr, 10);
            endptr = NULL;
            dst2 = strtol(sdst2, &endptr, 10);

            adj[src2][dst2] = 1;
        }

    // free everything
    for (int j = 0; j < *n; j++) {
        free(adj[j]);
    }
    //free(adj);
    return adj[0];
}


/*
 *  Synopsis        [Determine if a path exists from the src to the dst vertex
 *                  within the graph.]
 *  Return          [Returns 0 if no path exist. Returns 1 if a path exists.]
 *  Side effects    [Print a possible path from src to dst if one exists.]
 */
int find_path(int **adj_mat, int n, int src, int dst)
{
    // TODO if you want extra credit
    return 0;
}

int read_char(FILE *fptr) {
    // read character from file
    int ch = fgetc(fptr);

    // unexpected error?
    if (ferror(fptr)) {
        fprintf(stderr, "[ERROR]\n");
        exit(1);
    }

    return ch;

}


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "[ERROR] Usage: %s <input edge list>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        fprintf(stderr, "[ERROR] %s:%d: fopen() failed with '%s'\n", __FILE__, __LINE__, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Call to the parsing function
    int size;
    int **adj_mat = get_adj_mat(infile, &size);

    // Insert your calls to the path finding functions
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            find_path(adj_mat, size, i, j);
        }
    }

    fclose(infile);

    return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////