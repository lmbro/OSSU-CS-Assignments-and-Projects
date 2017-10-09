/*

File:        vigenere.c
Assignment:  Problem Set 2, Vigenere
Course:      CS250, 2017
Institution: Harvard
Access:      edX
Author:      Lucas Brown (LMBRO)
Date:        October 9, 2017

This course is part of the OSSU curriculum: https://github.com/ossu/computer-science


Summary
--------
Implement a program that encrypts messages using Vigenère’s cipher, per the below.

$ ./vigenere ABC
plaintext:  HELLO
ciphertext: HFNLP


Background
-----------
Vigenère’s cipher improves upon Caesar’s cipher by encrypting messages using a sequence of keys (or, put another way, a keyword). 

In other words, if p is some plaintext and k is a keyword (i.e., an alphbetical string, whereby A represents 0, B represents 1, C represents 2, …​, and Z represents 25), then each letter, c[i], in the ciphertext, c, is computed as:

c[i] = ( p[i] + k[j] ) mod 26

Note this cipher’s use of k[j] as opposed to just k. And if k is shorter than p, then the letters in k must be reused cyclically as many times as it takes to encrypt p.

In other words, if Vigenère himself wanted to say HELLO to someone confidentially, using a keyword of, say, ABC, he would encrypt the H with a key of 0 (i.e., A), the E with a key of 1 (i.e., B), and the first L with a key of 2 (i.e., C), at which point he’d be out of letters in the keyword, and so he’d reuse (part of) it to encrypt the second L with a key of 0 (i.e., A) again, and the O with a key of 1 (i.e., B) again. And so he’d write HELLO as HFNLP.


Specification
--------------
Design and implement a program that encrypts messages using Vigenère’s cipher.

- Implement your program in a file called vigenere.c
- Your program must accept a single command-line argument: a keyword, k, composed entirely of alphabetical characters.
- If your program is executed without any command-line arguments, with more than one command-line argument, or with one command-line argument that contains any non-alphabetical character, your program should print an error (of your choice) and exit immediately, with main returning 1 (thereby signifying an error).
- Otherwise, your program must proceed to prompt the user for a string of plaintext, p, (as by a prompt for plaintext:) which it must then encrypt according to Vigenère’s cipher with k, ultimately printing the result (prepended with ciphertext: and ending with a newline) and exiting, with main returning 0.
- With respect to the characters in k, you must treat A and a as 0, B and b as 1, …​ , and Z and z as 25.
- Your program must only apply Vigenère’s cipher to a character in p if that character is a letter. All other characters (numbers, symbols, spaces, punctuation marks, etc.) must be outputted unchanged. Moreover, if your code is about to apply the jth character of k to the ith character of p, but the latter proves to be a non-alphabetical character, you must wait to apply that jth character of k to the next alphabetical character in p; you must not yet advance to the next character in k.
- Your program must preserve the case of each letter in p.

*/

#include <ctype.h>  // toupper(), isaplpha()
#include <stdio.h>
#include <stdlib.h>

int _encrypt_in_bounds( int, int, int, int );

int main( int argc, char *argv[] ) {

    // Input Validation: Correct number of command-line arguments

    if( argc != 2 ) {
        printf( "Usage: ./caesar k\n" );
        return 1;
    }

    // Input Validation: Encryption key contains only alphabetic characters
    // Save time by determining length of encryption key with the incrementing index

    int key_length = 0; 

    while( argv[1][key_length] != '\n' && argv[1][key_length] != '\0' ) {
        
        if( isalpha( argv[1][key_length] ) == 0 ) {
            printf( "ERROR: Key contains non-alphabetic character at position %i\n", key_length );
            printf( "Exiting...\n" );
            return 1;
        }
        key_length++;
    }

    // User Input: Prompt user for and store plaintext (unecrpyted text)

    char plaintext[256];
    char ciphertext[256];
    
    printf( "plaintext:  " );
    fgets( plaintext, 255, stdin );

    // Convert encryption key from char array to int array
    // A and a = 0, Z and z = 25

    int key[key_length];
    for( int i = 0; i < key_length; i++ ) {
        key[i] = toupper( argv[1][i] ) - 65;
    }

    // Encryption loop

    int i = 0;  // Cipher/plaintext index
    int j = 0;  // Key index

    while( plaintext[i] != '\0' && plaintext[i] != '\n' ) {

        // Uppercase letters should remain uppercase ( ASCII 65 to 90 );
        // Lowercase letters should remain lowercase ( ASCII 97 to 122 );
        // Only convert letters, increment key index only when calling encryption function
        if( plaintext[i] >= 65 && plaintext[i] <= 90 ) {
            ciphertext[i] = _encrypt_in_bounds( plaintext[i], key[j++], 65, 90 );  
        } else if( plaintext[i] >= 97 && plaintext[i] <= 122 ) {
            ciphertext[i] = _encrypt_in_bounds( plaintext[i], key[j++], 97, 122 );
        } else {
            ciphertext[i] = plaintext[i];
        }
        i++;

        if( j == key_length ) {  // Loop back to beginning key when we run out of letters in the key
            j = 0;
        }
    }
    ciphertext[i] = '\0';  // End our string

    // Output: Print encrypted text

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