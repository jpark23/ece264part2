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
    int counter = 0;
    int ch;
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

        else if (isdigit(ch)) {
            counter++; // update the counter
            while (ch != '\n' && !feof(fptr)) {
                ch = read_char(fptr); // skip the rest of the line
            }
        }
    }
    *n = counter;

    // allocate the matrix
    int *adj[*n];// = malloc(*n * sizeof(int));  // TODO - segfault this method
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

    // once read an edge, replace entry from 0 to 1
    /*
    int ch;
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
    */
    // free everything
    for (int j = 0; j < *n; j++) {
        free(adj[j]);
    }
//    free(adj);  // TODO - only need this if using **adj = malloc
    return 0;
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
