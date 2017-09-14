#include <stdlib.h>
#include <stdio.h>

int main( void ) {

    long x, y;
    char str[256];

    printf( "Enter value for x: " );
    fgets( str, 256, stdin );
    x = strtol( str, NULL, 0 );

    printf( "Enter value for y: " );
    fgets( str, 256, stdin );
    y = strtol( str, NULL, 0 );

    printf( "%li plus %li is %li\n", x, y, x + y );
    printf( "%li minus %li is %li\n", x, y, x - y );
    printf( "%li times %li is %li\n", x, y, x * y );
    printf( "%li divided by %li is %li\n", x, y, x / y );
    printf( "The remainer of %li divided by %li is %li\n", x, y, x % y );
}