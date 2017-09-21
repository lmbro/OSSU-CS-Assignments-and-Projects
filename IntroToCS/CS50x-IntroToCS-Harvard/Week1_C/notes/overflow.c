#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main( void ) {

    int n = 1;
    for( int i = 0; i < 64; i++ ) {
        printf( "n is %i\n", n );
        n *= 2;
    }

    long long x = 1;
    for( int i = 0; i < 64; i++ ) {
        printf( "x is %lld\n", x );
        x *= 2;
    }
}