#include <stdio.h>

int main( void )  {

    char name[256];

    printf( "Name: " );
    fgets( name, 256, stdin );
    printf( "hello, %s\n", name );
}