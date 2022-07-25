#include <stdio.h>
#include <stdlib.h>


int main(){
    
    int num=123;
    int* pointer = &num;

    printf("%p\n" , pointer );
    printf("%d\n" , *(pointer) );

    // printf("%p\n" , &num );
    printf("%d\n" , *(&num) );


    return 0;
}