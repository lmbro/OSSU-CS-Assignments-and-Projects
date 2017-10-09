/*

File:        caesar.c
Assignment:  Problem Set 2, Caesar
Course:      CS250, 2017
Institution: Harvard
Access:      edX
Author:      Lucas Brown (LMBRO)
Date:        Ocotober 9, 2017

This course is part of the OSSU curriculum: https://github.com/ossu/computer-science


Summary
--------
Implement a program that encrypts messages using Caesar’s cipher, per the below.

$ ./caesar 13
plaintext:  HELLO
ciphertext: URYYB


Background
-----------
Supposedly, Caesar (yes, that Caesar) used to "encrypt" (i.e., conceal in a reversible way) confidential messages by shifting each letter therein by some number of places. For instance, he might write A as B, B as C, C as D, …​, and, wrapping around alphabetically, Z as A. And so, to say HELLO to someone, Caesar might write IFMMP. Upon receiving such messages from Caesar, recipients would have to "decrypt" them by shifting letters in the opposite direction by the same number of places.

Unencrypted text is generally called plaintext. Encrypted text is generally called ciphertext. And the secret used is called a key.

More generally, Caesar’s algorithm (i.e., cipher) encrypts messages by "rotating" each letter by k positions. More formally, if p is some plaintext (i.e., an unencrypted message), p[i] is the ith character in p, and k is a secret key (i.e., a non-negative integer), then each letter, c[i], in the ciphertext, c, is computed as:

c[i] = ( p[i] + k ) mod(26)

wherein mod(26) here means "remainder when dividing by 26." This formula perhaps makes the cipher seem more complicated than it is, but it’s really just a concise way of expressing the algorithm precisely.


Specification
--------------
Design and implement a program, caesar, that encrypts messages using Caesar's cipher.
- Implement your program in a file called caesar.c
- Your program  must accept a single command-lien argument, a non-negative integer. Let's call it k for the sake of discussion.
- If your program is executed without any command-line arguements or with more than one command-line argument, your program should print an error message of your choice (with printf) and return from main a value of 1 (which tends to signify an error) immediately.
- You can assume that, if a user does provide a command-line argument, it will be a non-negative integer (e.g., 1). No need to check that it's indeed numeric.
- Do not assume that k will be less than or equal to 26. Your program should work for all non-negative integral values of k less than 231 - 26. In other words, you don’t need to worry if your program eventually breaks if the user chooses a value for k that’s too big or almost too big to fit in an int. (Recall that an int can overflow.) But, even if k is greater than 26, alphabetical characters in your program’s input should remain alphabetical characters in your program’s output. For instance, if k is 27, A should not become [ even though [ is 27 positions away from A in ASCII, per asciichart.com; A should become B, since B is 27 positions away from A, provided you wrap around from Z to A.
- Your program must output plaintext: (without a newline) and then prompt the user for a string of plaintext (using get_string)- Your program must output ciphertext: (without a newline) followed by the plaintext’s corresponding ciphertext, with each alphabetical character in the plaintext "rotated" by k positions; non-alphabetical characters should be outputted unchanged.
- Your program must preserve case: capitalized letters, though rotated, must remain capitalized letters; lowercase letters, though rotated, must remain lowercase letters.
- After outputting ciphertext, you should print a newline. Your program should then exit by returning 0 from main.

*/

#include <stdlib.h>
#include <stdio.h>

int _encrypt_in_bounds( int, int, int, int );

int main( int argc, char *argv[] ) {

    if( argc != 2 ) {
        printf( "Usage: ./caesar k\n" );
        return 0;
    }

    int k = atoi( argv[1] );  // Guaranteed  by problem statement to be a positive integer
    char plaintext[256];
    char ciphertext[256];

    printf( "plaintext:  " );
    fgets( plaintext, 255, stdin );

    // Encryption loop
    int i = 0;
    while( plaintext[i] != '\0' && plaintext[i] != '\n' ) {

        // Uppercase letters should remain uppercase ( ASCII 65 to 90 );
        // Lowercase letters should remain lowercase ( ASCII 97 to 122 );
        // Only convert letters
        if( plaintext[i] >= 65 && plaintext[i] <= 90 ) {
            ciphertext[i] = _encrypt_in_bounds( plaintext[i], k, 65, 90 );
        } else if( plaintext[i] >= 97 && plaintext[i] <= 122 ) {
            ciphertext[i] = _encrypt_in_bounds( plaintext[i], k, 97, 122 );
        } else {
            ciphertext[i] = plaintext[i];
        }
        i++;
    }
    ciphertext[i] = '\0';  // End our string

    printf( "ciphertext: %s\n", ciphertext );

    return 0;
}

int _encrypt_in_bounds( int letter, int key, int lower, int upper ) {

    int cipher = letter + key;

    while( cipher > upper ) {
        cipher = ( lower - 1 ) + ( cipher - upper );  // Written for clarity;
    }

    return cipher;
}