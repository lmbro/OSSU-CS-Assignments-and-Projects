#include <stdlib.h>
#include <stdio.h>

int main( void ) {

    float x, y;
    char str[256];

    printf( "Enter value for x: " );
    fgets( str, 256, stdin );
    x = strtof( str, NULL );

    printf( "Enter value for y: " );
    fgets( str, 256, stdin );
    y = strtof( str, NULL );

    printf( "%f plus %f is %f\n", x, y, x + y );
    printf( "%f minus %f is %f\n", x, y, x - y );
    printf( "%f times %f is %f\n", x, y, x * y );
    printf( "%f divided by %f is %f\n", x, y, x / y );
}