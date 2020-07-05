//////////////////////////////////////////////////////////////////////////////////////////
//                                         PA04                                         //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// You can use these constant in your find_path function.
#define PRESENT 1
#define ABSENT  0

/*
 *  Synopsis        [Build the adjacency matrix representation of a graph
 *                  from a valid edge list.]
 *  Return          [Returns a pointer to the adjacency matrix on the heap.]
 *  Side effects    [The n argument is populated with the number of vertices
 *                  in the input graph.]
 */
int **get_adj_mat(FILE *fptr, int *n)
{
    // TODO
}


/*
 *  Synopsis        [Determine if a path exists from the src to the dst vertex
 *                  within the graph.]
 *  Return          [Returns 0 if no path exist. Returns 1 if a path exists.]
 *  Side effects    [Print a possible path from src to dst if one exists.]
 */
int find_path(int **adj_mat, int n, int src, int dst)
{
    // TODO
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