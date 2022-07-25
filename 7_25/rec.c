#include <stdio.h>
#include <stdlib.h>

void rec1(){
    return;
    printf("word");
    return;
}

int rec2(int num2){
    return 1;
}

int rec3(int num){

    if( num > 10 ){
        return 0;
    }

    printf("%d\n" , num );
    rec3( num+1 );

    return 0;
}

/*
    num:1
    rec3 : 1{
        rec3 : 2{
           rec3 : 3{
                ....
            } 
        }
    }
*/

void rec4(){
    rec4();
}

float fun1(){
    return 3.14;
}


void funTest(int a){
    a=10;
}
void funPointer(int* ptr){
    *ptr=10;
}
int main(){
    int a=100;
    printf("funTest : \n");
    printf("%d\n" , a );
    funTest( a );
    printf("%d\n" , a );
    printf("funPointer : \n");
    funPointer( &a ) ;
    printf("%d\n" , a );
    return 0;
}