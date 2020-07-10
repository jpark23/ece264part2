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

    // allocate the matrix
    int** adj = malloc(*n * sizeof(int *)); 
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

            adj[src2-1][dst2-1] = 1;
        }
    }

    // print the matrix
    printf("\nAdjacency Matrix:\n");
    int row2, col2;
    for (row2 = 0; row2 < *n; row2++) {
        for (col2 = 0; col2 < *n; col2++) {
            printf("%d ", adj[row2][col2]);
        }
        printf("\n");
    }
    printf("\n");
    return adj;
}

int create_int_buffer(int size) {
	int *buffer = malloc(size * sizeof(int));
    if (buffer == NULL) {
		exit(EXIT_FAILURE);
		}
		
		return buffer; // returns pointer to buffer space we just allocated
}

void insert_buffer(int *buffer, int *start, int *end, int data, int buffer_size) {
	if ((*end + 1) % buffer_size != *start) {
		data = buffer[*end]; // next available set in the buffer can have data stored in it
		// don't forget to do the wrap thing
		*end = (*end + 1) % buffer_size; // this is the wrap, the % buffer size
		printf ("inserted: %d\n", data);
	}
	else 
		Print ("buffer full");
	}
	
int remove_buffer(int *buffer, int *start, int *end, int data, int buffer_size) {
	int data;
	if (*end != *start) {
	    data = buffer[*start];
		*start = (*start + 1) % buffer_size;
		printf("removed %d\n", data);
	}
	else {
		printf("buffer_empty\n");
		data = -1;
    }

    return data;
}

/*
 *  Synopsis        [Determine if a path exists from the src to the dst vertex
 *                  within the graph.]
 *  Return          [Returns 0 if no path exist. Returns 1 if a path exists.]
 *  Side effects    [Print a possible path from src to dst if one exists.]
 */
int find_path(int **adj_mat, int n, int src, int dst)
{
    int buffer_size = n;
    int explored_buffer = create_int_buffer(n);
    int discovered_buffer = create_int_buffer(n);
    
    // initalize buffer indicators
    int ex_start, ex_end = 0;
    int disc_start, disc_end = 0;

    // How to use the buffer
    // insert_buffer(buffer, &start, &end, data, n); 
    // remove_buffer(buffer, &start, &end);
    // start is the first index out, I think

    // first index in explored buffer is src
    insert_buffer(explored_buffer, &ex_start, &ex_end, src, n);

    // as we find indices, we add them to the explored buffer
    // remember, adj matrix coords = (row, column)
    for (int col = 0; col < n; col++) {
        if (adj_mat[src][col] == 1) {
            insert_buffer(explored_buffer, &ex_start, &ex_end, col, n);
        }
    }

    insert_buffer(discovered_buffer, &disc_start, &disc_end, src, n);

    return 0; // don't forget to free the buffers
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
    
    // free the matrix
    for (int j = 0; j < size; j++) {
        free(adj_mat[j]);
    }
    free(adj_mat);

    return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////