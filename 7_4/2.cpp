#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    char name[100]="your name" ;
    int id=123;
    printf( "name : %s , id : %d\n\n" , name , id );

    float floatArr[] ={ 12.3  , 12.345 , 12.3456 , 12.0};
    printf("float : %.2f %.2f %.1f %.2f\n\n",floatArr[0],floatArr[1],floatArr[2],floatArr[3]);

    int num12;
    printf("%f\n\n" , num12 );



    for(int i=1;i<=7;i+=2){
        for(int j=0;j<(7-i)/2;j++){
            printf(" ");
        }
        for(int j=0;j<i;j++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n");


    char john[100] = "John Wick";
    float box = 171.5;

    printf("%s a 2014 America neo-noir action thriller film,%s:\nChapter Two made $%.1f million in 2017.\n" , john , john , box); 
    return 0;
}