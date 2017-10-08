#include <stdlib.h>
#include <stdio.h>

void selection_print( int[], int );
void print_arr( int[], int );
void swap( int[], int, int );

int main( void ) {

    int arr[5] = { 10, 1, 4, 5, 2 };

    selection_print( arr, 5 );

    return 0;   
}

void selection_print( int arr[], int size ) {

    int num_swap = 0;
    int pass = 1;

    printf( "\n\n---------------------------\n" );
    printf( "      Selection Sort\n" );
    printf( "---------------------------\n\n" );

    for( int i = 0; i < size-1; i++ ) {

        printf( "\n\n-------------\n" );
        printf( " Pass: %i\n", pass++ );
        printf( "-------------\n" );

        int min = size;  // No negative numbers
        int min_index = size + 1;

        // Find smallest number in the unsorted section of the array ( arr[i] through arr[size-1]
        for( int j = i; j < size; j++ ) {

            if( arr[j] < min ) {
                min = arr[j];
                min_index = j;
            }
        }

        print_arr( arr, size );
        printf( "Position: %i\n", i );
        printf( "Minimum: %i\n", min );        

        // Place the smallest number at the end of the sorted section of the array ( arr[0] through arr[i] )
        if( i != min_index && min_index != size+1 ) {
            swap( arr, i, min_index );
            num_swap++;
        }

        print_arr( arr, size );
    }

    printf( "\n\n----------------\n" );
    printf( "Selection Sort\n" );
    printf( "----------------\n" );
    printf( "Number of Swaps: %i\n", num_swap );
    print_arr( arr, size );

    return;
}

void print_arr( int arr[], int size ) {

    for( int i = 0; i < size-1; i++ ) {
        printf( "%i, ", arr[i] );
    }
    printf( "%i\n", arr[size-1] );

    return;
}

void swap( int arr[], int a, int b ) {

    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;

    return;
}

void verify( int arr[], int size ) {

    for( int i = 0; i < size-1; i++ ) {
        if( arr[i] > arr[i+1] ) {
            printf( "NOT SORTED" );
            return;
        }
    }

    printf( "Verified sorted\n" );
    return;
}