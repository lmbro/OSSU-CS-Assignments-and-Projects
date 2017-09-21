/*

File:        water.c
Assignment:  Problem Set 1, Water
Course:      CS250, 2017
Institution: Harvard
Access:      edX
Author:      Lucas Brown
Date:        September 21, 2017

This is an assignment and course are part of the OSSU curriculum: https://github.com/ossu/computer-science

NOTE: I am doing this problem set is done without using the CS50 library, which contains functions for user input among other things.


Background
-----------
Suffice it to say that the longer you shower, the more water you use. But just how much? Even if you have a "low-flow" showerhead, odds are your shower spits out 1.5 gallons of water per minute. A gallon, meanwhile, is 128 ounces, and so that shower spits out 1.5 × 128 = 192 ounces of water per minute. A typical bottle of water (that you might have for a drink, not a shower), meanwhile, might be 16 ounces. So taking a 1-minute shower is akin to using 192 ÷ 16 = 12 bottles of water. Taking (more realistically, perhaps!) a 10-minute shower, then, is like using 120 bottles of water. Deer Park, that’s a lot of water! Of course, bottled water itself is wasteful; best to use reusable containers when you can. But it does put into perspective what’s being spent in a shower!


Specification
--------------
Write, in a file called water.c, a program that prompts the user for the length of his or her shower in minutes (as a positive integer) and then prints the equivalent number of bottles of water (as an integer)

For simplicity, you may assume that the user will input a positive integer, so no need for error-checking (or any loops) this time! And no need to worry about overflow!

*/

#include <stdlib.h>
#include <stdio.h>

int main( void ) {

    char input[256];
    long minutes;

    // Request input (matching example)
    printf( "Minutes: " );

    // Use fgets and strtol to store input (no stroi, long works just fine)
    fgets( input, 256, stdin );
    minutes = strtol( input, NULL, 0 );

    // Output (matching example)
    printf( "Bottles: %li\n", minutes * 12 );
}