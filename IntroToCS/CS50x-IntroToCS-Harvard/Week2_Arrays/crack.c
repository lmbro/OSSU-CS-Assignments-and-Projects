/*

File:        crack.c
Assignment:  Problem Set 2, Crack 
Course:      CS250, 2017
Institution: Harvard
Access:      edX
Author:      Lucas Brown (LMBRO)
Date:        October 12, 2017

This course is part of the OSSU curriculum: https://github.com/ossu/computer-science


Summary
--------
Implement a program that cracks passwords, per the below.

$ ./crack 50fkUxYHbnXGw
rofl


Background
-----------
On most systems running Linux these days is a file called /etc/shadow, which contains usernames and passwords. Fortunately, the passwords therein aren’t stored "in the clear" but are instead encrypted using a "one-way hash function." When a user logs into these systems by typing a username and password, the latter is encrypted with the very same hash function, and the result is compared against the username’s entry in /etc/shadow. If the two hashes match, the user is allowed in. If you’ve ever forgotten some password, you might have been told that tech support can’t look up your password but can change it for you. Odds are that’s because tech support can only see, if anything at all, a hash of your password, not your password itself. But they can create a new hash for you.

Even though passwords in /etc/shadow are hashed, the hash function is not always that strong. Quite often are adversaries, upon obtaining that file somehow, able to guess (and check) users' passwords or crack them using brute force (i.e., trying all possible passwords). Below is what /etc/shadow might look like, albeit simplified, wherein each line is formatted as username:hash.

andi:50.jPgLzVirkc
jason:50YHuxoCN9Jkc
malan:50QvlJWn2qJGE
mzlatkova:50CPlMDLT06yY
patrick:50WUNAFdX/yjA
rbowden:50fkUxYHbnXGw
summer:50C6B0oz0HWzo
stelios:50nq4RV/NVU0I
wmartin:50vtwu4ujL.Dk
zamyla:50i2t3sOSAZtk


Specification
--------------
Design and implement a program, crack, that cracks passwords.
- Implement your program in a file called crack.c in a directory called crack.
- Your program should accept a single command-line argument: a hashed password.
- If your program is executed without any command-line arguments or with more than one command-line argument, your program should print an error (of your choice) and exit immediately, with main returning 1 (thereby signifying an error).
- Otherwise, your program must proceed to crack the given password, ideally as quickly as possible, ultimately printing the password in the clear followed by \n, nothing more, nothing less, with main returning 0.
- Assume that each password has been hashed with C’s DES-based (not MD5-based) crypt function.
- Assume that each password is no longer than (gasp) four characters
- Assume that each password is composed entirely of alphabetical characters (uppercase and/or lowercase).

*/

// Compiled on Linux with "gcc crack.c -lcrypt"

#define _XOPEN_SOURCE  // crypt()

#include <stdbool.h> // true/false keywords
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // crypt()

void _increment_guess( char *, int );
bool compare_by_char( char *, char * );

int main( int argc, char *argv[] ) {

    // Read command-line Arguments

    if( argc != 2 ) {
        printf( "ERROR: Incorrect number of arguments\n" );
        printf( "Usage: ./crack k\n" );
        return 1;
    }

    char password[5] = "A";
    char lock[3] = { argv[1][0], argv[1][1] };

    while( compare_by_char( crypt( password, lock ), argv[1] ) != true ){
        _increment_guess( password, 0 );
        //printf( "%s\n", crypt( password, lock ) );
    }

    printf( "%s\n", password );

    return 0;
}

void _increment_guess( char *password, int i ) {
   
    if( i > 4 ) {
        printf( "ERROR: We done goofed and ran out of guesses without finding the password!\n" );
        exit(1);
    } else if( password[i] == '\0' ) {
        password[i] = 'A';
    } else {
        password[i]++;
    }

    if( password[i] == 91 ) {
        password[i] = 97;
    } else if( password[i] == 123 ) {
        password[i] = 65;
        _increment_guess( password, i+1 );
    }

    return;
}

bool compare_by_char( char *guess, char *hash ) {

    int i = 0;
    while( guess[i] != '\0' && hash[i] != '\0' ) {

        if( guess[i] != hash[i] ) {
            return false;
        }

        i++;
    }

    return true;
}