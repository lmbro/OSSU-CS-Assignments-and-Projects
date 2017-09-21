#include <stdlib.h>
#include <stdio.h>

int main( void ) {

    printf( "bool is %lu\n", sizeof(_Bool) ); // #include <stdbool.h> to use bool isntead of _Bool
    printf( "char is %lu\n", sizeof(char) );
    printf( "double is %lu\n", sizeof(double) );
    printf( "float is %lu\n", sizeof(float) );
    printf( "int is %lu\n", sizeof(int) );
    printf( "long long is %lu\n", sizeof(long long) );
}
