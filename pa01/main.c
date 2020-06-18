//////////////////////////////////////////////////////////////////////////////////////////
//                                         PA01                                         //
//////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE    10
#define MAX     100


/*
 *  Synopsis        [Print the contents of an integer array to stdin.]
 *  Return          [None.]
 *  Side effects    [None.]
 */
void print_array(int const *arr, int size)
{
    int lcv;
    printf("[");
    for (lcv = 0; lcv < size-1; lcv++) {
        printf("%d", arr[lcv]);
        printf(",");
    }
    printf("%d", arr[size-1]);
    printf("]");

    return;
}


/*
 *  Synopsis        [Populate an array with pseudo-random integers.]
 *  Return          [None.]
 *  Side effects    [None.]
 */
void generate_test_array(int *arr, int size, int max)
{
    //srand(time(NULL));
    //RAND_MAX = max;
    int ind;
    int insert;
    
    for (ind = 0; ind <= size; ind++) {

        insert = max + 1; // reset insert every time
        // generate the random number to be added
        while (insert >= max || insert <= 0) {
            insert = rand();
        }

        // change the array value to be the random number
        arr[ind] = insert;
    }

    return;
}


/*
 *  Synopsis        [Sorts the entries of an integer array in place.]
 *  Return          [None.]
 *  Side effects    [None.]
 */
void selection_sort(int *arr, int size)
{
    // TODO
}


int main()
{
    /*
     * Create a test array on the stack. The test array consists of SIZE (#define above)
     * integers from zero to (MAX - 1) (#defined above) pseudo-randomly generated using
     * the rand() function available through stdlib.h.
     */
    printf("Creating test arrays... "); fflush(stdout);
    int test[SIZE]; // Declare the test array
    srand(time(NULL)); // Seed the pseudo-random number generator
    generate_test_array(test, SIZE, MAX); // Generate the test array
    printf("done!\n");

    /*
     * Print the unsorted test array.
     */
    printf("Unsorted array:\t");
    print_array(test, SIZE);

    /*
     * Call to the sort function to sort the array in place, in ascending order, using
     * selection sort.
     */
    printf("Sorting... "); fflush(stdout);
    selection_sort(test, SIZE);
    printf("done!\n");

    /*
     * Print the sorted test array.
     */
    printf("Sorted array:\t");
    print_array(test, SIZE);

    return EXIT_SUCCESS;
}

//////////////////////////////////////////////////////////////////////////////////////////
//                                      END OF FILE                                     //
//////////////////////////////////////////////////////////////////////////////////////////