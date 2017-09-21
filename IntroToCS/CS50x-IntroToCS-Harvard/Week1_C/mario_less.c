/*

File:        mario_less.c
Assignment:  Problem Set 1, Mario (less comfortable)
Course:      CS250, 2017
Institution: Harvard
Access:      edX
Author:      Lucas Brown
Date:        September 21, 2017

This is an assignment and course are part of the OSSU curriculum: https://github.com/ossu/computer-science


Background
-----------
Toward the end of World 1-1 in Nintendo’s Super Mario Brothers, Mario must ascend a "half-pyramid" of blocks before leaping (if he wants to maximize his score) toward a flag pole. 


Specification
--------------
- Write, in a program that recreates this half-pyramid using hashes (#) for blocks.
- To make things more interesting, first prompt the user for the half-pyramid’s height, a non-negative integer no greater than 23. (The height of the half-pyramid pictured above happens to be 8.)
- If the user fails to provide a non-negative integer no greater than 23, you should re-prompt for the same again.
- Then, generate (with the help of printf and one or more loops) the desired half-pyramid.
- Take care to align the bottom-left corner of your half-pyramid with the left-hand edge of your terminal window.

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

        int hash = 2 + i; // Looking at the example, there are two hashes (or steps) on line 0

        // Print spaces
        for( int j = 0; j < height-hash+1; j++ ) {
            printf(" ");
        }

        // Print steps
        for( int j = 0; j < hash; j++ ) {
            printf("#");
        }
        
        // End row
        printf("\n");
    }

}