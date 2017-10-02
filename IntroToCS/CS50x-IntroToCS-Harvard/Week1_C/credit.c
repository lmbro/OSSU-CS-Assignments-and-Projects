/*

File:        credit.c
Assignment:  Problem Set 1, Credit
Course:      CS250, 2017
Institution: Harvard
Access:      edX
Author:      Lucas Brown (LMBRO)
Date:        September 25, 2017

This is an assignment and course are part of the OSSU curriculum: https://github.com/ossu/computer-science


Background
-----------
LMBRO: I cut out some non-informative text to keep this shorter. It was lighthearted and goofy, so just take my word for it and smile, maybe even chuckle. 

Odds are you or someone you know has a credit card. That card has a number, both printed on its face and embedded (perhaps with some other data) in the magnetic stripe on back. That number is also stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. There are a lot of people with credit cards in this world, so those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. 

American Express numbers all start with 34 or 37; MasterCard numbers all start with 51, 52, 53, 54, or 55; and Visa numbers all start with 4. But credit card numbers also have a "checksum" built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.

So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn, a nice fellow from IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

- Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
- Add the sum to the sum of the digits that weren’t multiplied by 2.
- If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!


Specification
--------------
- In credit.c, write a program that prompts the user for a credit card number and then reports (via printf) whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein.
- So that we can automate some tests of your code, we ask that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less, and that main always return 0.
- For simplicity, you may assume that the user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card).
- Do not assume that the user’s input will fit in an int! Best to use get_long_long from CS50’s library to get users' input. (Why?)
    -- LMBRO: I'm not using the CS50 Library, and to answer the (Why?), an int isn't big enough to hold a 16-digit number. That being said, I think using a long long isn't necessary - the problem seems easier using a character array.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // Allows use of true and false keywords instead of 1 and 0 for booleans

int main( void ) {

    char card_number[256];
    char creditor;
    int digits = 0;

    printf( "Number: " );
    fgets( card_number, 256, stdin );



    // Check who the creditor could be based on first two numbers

    if( card_number[0] == '4' ) {
        creditor = 'V';  // VISA
    } else if( card_number[0] == '3' && ( card_number[1] == '4' || card_number[1] == '7' ) ) {
        creditor = 'A';  // AMEX
    } else if( card_number[0] == '5' && ( (int)card_number[1] - '0' < 6 && card_number[1] != '0' ) ) {
        creditor = 'M';  // MASTERCARD
    } else {
        printf( "INVALID\n" );
        return 0;
    }



    // Check validity based on possible creditor and number length

    for( int i = 0; i < 17; i++ ) {
        /*
            Find length based on where the newline character, \n, or the null terminator, \0, is located.
            The user hits enter after entering card number, so \n should be sufficient. \0 is just a safety net, all strings end with \0.
            There's no need to check past 17 digits - the largest possible is 16.
        */
        if( card_number[i] == '\n' || card_number[i] == '\0' ) {
            break;
        }
        digits++;
    }

    switch( creditor ) {

        case 'V':
            if( digits != 13 && digits != 16 ) {
                printf( "INVALID\n" );
                return 0;
            }
            break;
        case 'A':
            if( digits != 15 ) {
                printf( "INVALID\n" );
                return 0;
            }
            break;
        case 'M':
            if( digits != 16 ) {
                printf( "INVALID\n" );
                return 0;
            }
            break;
        default:
            printf( "ERROR: INVALID CREDITOR FOR LENGTH CHECK\n" );
            return 0;
    }



    // Use Luhn's algorithm to verify card number is syntactically valid

    bool flipadelphia = true;
    int mult_by_two = 0;
    int the_others = 0;

    for( int i = digits-1; i >= 0; i-- ) {

        if( flipadelphia ) {
            the_others += (int)card_number[i] - '0';
            flipadelphia = false;
        } else {
            int temp = 2 * ( (int)card_number[i] - '0' );
            mult_by_two += temp / 10 + temp % 10;  // Add digits of products together. Products are 1 or 2 digits - this works for both. 
            flipadelphia = true;
        }
    }

    if( ( mult_by_two + the_others ) % 10 != 0 ) {
        printf( "INVALID\n" );
        return 0;
    }

    switch( creditor ) {

        case 'V':
            printf( "VISA\n" );
            break;
        case 'A':
            printf( "AMEX\n" );
            break;
        case 'M':
            printf( "MASTERCARD\n" );
            break;
        default:
            printf( "ERROR: INVALID CREDITOR AFTER LUHN'S CHECK\n" );
            return 0;
    }

    return 0;
}
