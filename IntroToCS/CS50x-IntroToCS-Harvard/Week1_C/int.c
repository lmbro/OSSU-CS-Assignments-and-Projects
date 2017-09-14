#include <stdlib.h>
#include <stdio.h>

int main( void ) {

    char str[256];
    long number;

    printf( "Enter a number: " );
    fgets( str, 256, stdin );
    number = strtol( str, NULL, 0 );
    printf( "Hello, %li\n", number );
}