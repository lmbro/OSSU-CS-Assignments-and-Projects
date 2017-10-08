/*

File:        mario_more.c
Assignment:  Problem Set 1, Mario (more comfortable)
Course:      CS250, 2017
Institution: Harvard
Access:      edX
Author:      Lucas Brown
Date:        September 21, 2017

This course is part of the OSSU curriculum: https://github.com/ossu/computer-science


Background
-----------
Toward the beginning of World 1-1 in Nintendo’s Super Mario Brothers, Mario must hop over two "half-pyramids" of blocks as he heads toward a flag pole. 


Specification
--------------
- Write, in a file called mario.c, a program that recreates these half-pyramids using hashes (#) for blocks. (NOTE: two spaces separate the half-pyramids).
- To make things more interesting, first prompt the user for the half-pyramids' heights, a non-negative integer no greater than 23. 
- If the user fails to provide a non-negative integer no greater than 23, you should re-prompt for the same again.
- Then, generate (with the help of printf and one or more loops) the desired half-pyramids.
- Take care to left-align the bottom-left corner of the left-hand half-pyramid with the left-hand edge of your terminal window.

*/

#include <stdio.h>
#include <stdlib.h>

int main( void ) {

    char input[256];
    long height;

    do {
        printf( "Height: " );
        fgets( input, 256, stdin );
        height = strtol( input, NULL, 0 );
    } while( height < 0 || height > 23 );


    for( int i = 0; i < height; i++ ) {

        int hash = 1 + i; // Looking at the example, there is hash (or step) on line 0

        // Print spaces for left steps
        for( int j = 0; j < height-hash+1; j++ ) {
            printf(" ");
        }

        // Print left steps
        for( int j = 0; j < hash; j++ ) {
            printf("#");
        }
        
        // Print gap
        printf( "  " );

        // Print right steps
        for( int j = 0; j < hash; j++ ) {
            printf("#");
        }

        // End row
        printf("\n");
    }

}