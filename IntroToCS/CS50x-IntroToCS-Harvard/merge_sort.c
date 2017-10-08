/*

File:        merge_sort.c
Assignment:  Not an Assignment, Independent Study on Merge Sort
Course:      CS250, 2017
Institution: Harvard
Access:      edX
Author:      Lucas Brown (LMBRO)
Date:        October 2, 2017

This course is part of the OSSU curriculum: https://github.com/ossu/computer-science


Summary (LMBRO)
----------------
Implementation of bubble, selection, insertion, and merge sort algorithms, as discussed during the Week 3 lecture on algorithms.


Background (LMBRO)
-------------------
During week 3's lecture on Algorithms, search and sort algorithms were covered. More specifically, the sort algorithms bubble, selection, isertion, and merge sort were explained. I was very interested in how much faster merge sort is than all the others, so I decided it would be a good learning experience to implement all of these algorithms in C. 

The specification includes a few extra things outside the scope of this course, such as creating an array of random numbers, timing the execution time, and using functions with arrays. I have some experience with C, so this serves to strengthen and refresh some fundamental skills in C.


Specification (LMBRO)
----------------------
- Implement a bubble sort agorithm in a function called bubble
- Implement a selection sort algorithm in a function called selection
- Implement a insertion sort algorithm in a function called insertion
- Implement a merge sort algorithm in a function called merge
    - The file is named merge_sort since the merge sort is by far the most important algorithm implemented here. The others are bonus, more or less, and used mostly for comparison.
- Time (in real world time) how long it takes for each computation to complete

*/

#include <ctype.h>  // toupper()
#include <stdbool.h>  // true/false keywords
#include <stdlib.h>
#include <stdio.h>
#include <time.h>  // time


void print_arr( int[], int );
void swap( int[], int );
void verify( int[], int );

void bubble( int[], int );
void selection( int[], int );
void insertion( int[], int );
void merge( int[], int );

// _print functiosn print out the steps. This was mostly intended for verification of algorithms, but I left them in as an option so the individual steps are viewable.
void bubble_print( int[], int );
void selection_print( int[], int );
void insertion_print( int[], int );
void merge_print( int[], int );


int main( void ) {

    char input[256];
    int size;
    bool print_on;

    printf( "Array size: " );
    fgets( input, 256, stdin );
    size = strtol( input, NULL, 0 );

    do {
        printf( "Print steps (y\\n)? " );
        fgets( input, 256, stdin );
    } while( toupper(input[0]) != 'Y' && toupper(input[0]) != 'N' );

    if( toupper(input[0]) == 'Y' ) {
        print_on = true;
    } else {
        print_on = false;
    }
    
    int bubble_array[size];
    int selection_array[size];
    int insertion_array[size];
    int merge_array[size];

    // Fill arrays with random numbers between 0 and size
    srand( time(NULL) );
    for( int i = 0; i < size; i++ ) {

        // http://c-faq.com/lib/randrange.html
        int number = rand() / ( RAND_MAX / size + 1 ); 

        bubble_array[i] = number;
        selection_array[i] = number;
        insertion_array[i] = number;
        merge_array[i] = number; 
    }

    printf( "\n---------------------------\n" );
    printf( " Sort algorithm comparison\n" );
    printf( "---------------------------\n" );
    printf( "Array Size: %i\n", size );

    if( print_on ) {
        bubble_print( bubble_array, size );
        selection_print( selection_array, size );
        insertion_print( insertion_array, size );
        merge_print( merge_array, size );
    } else {
        bubble( bubble_array, size );
        selection( selection_array, size );
        insertion( insertion_array, size );
        merge( merge_array, size );
    }

    return 0;
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

void bubble( int arr[], int size ) {

    int num_swap = 0;

    for( int i = size; i > 0; i-- ) {

        bool noswap = true;

        for( int j = 1; j < i; j++ ) {

            if( arr[j] < arr[j-1] ) {
                swap( arr, j-1, j );
                num_swap++;
                noswap = false;
            }
        }

        if( noswap ) {
            break;
        }
    }

    printf( "\n-------------\n" );
    printf( "Bubble Sort\n" );
    printf( "-------------\n" );
    printf( "Number of Swaps: %i\n", num_swap );
    verify( arr, size );
    
    return;
}

void selection( int arr[], int size ) {

    printf( "You've just been selected\n" );

    return;
}

void insertion( int arr[], int size ) {

    printf( "You've just been inserted\n" );

    return;
}

void merge( int arr[], int size ) {

    printf( "You've just been merged\n" );

    return;
}

void bubble_print( int arr[], int size ) {

    int num_swap = 0;
    int pass = 1;

    printf( "\n\n---------------------------\n" );
    printf( "      Bubble Sort\n" );
    printf( "---------------------------\n\n" );
    print_arr( arr, size );

    for( int i = size; i > 0; i-- ) {

        printf( "\n\n-------------\n" );
        printf( " Pass: %i\n", pass++ );
        printf( "-------------\n" );

        bool noswap = true;
        int pair = 1;

        for( int j = 1; j < i; j++ ) {

            printf( "\nPair: %i\n\n", pair++ );
            printf( "arr[%i] <? arr[%i]\n", j-1, j );       
            print_arr( arr, size );

            if( arr[j] < arr[j-1] ) {
                swap( arr, j-1, j );
                printf( "swap\n" );
                num_swap++;
                noswap = false;
                print_arr( arr, size );
            }
        }

        if( noswap ) {
            break;
        }
    }

    printf( "\n\n-------------\n" );
    printf( "Bubble Sort\n" );
    printf( "-------------\n" );
    printf( "Number of Swaps: %i\n", num_swap );
    print_arr( arr, size );
    
    return;
}

void selection_print( int arr[], int size ) {

    printf( "You've just been selected\n" );

    return;
}

void insertion_print( int arr[], int size ) {

    printf( "You've just been inserted\n" );

    return;
}

void merge_print( int arr[], int size ) {

    printf( "You've just been merged\n" );

    return;
}