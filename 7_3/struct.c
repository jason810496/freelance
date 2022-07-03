#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct student{
    char id[8];
    char name[20];
    int score1 , score2;
};

typedef struct student student;

int main() {
    int n ;
    scanf( "%d" , &n );

    student *arr = malloc( n*sizeof(student) );

    char c , ptr[1];
    for(int i=0;i<n;i++){
        scanf( "%s" ,arr[i].id );
        c=getchar(); // space
        c=getchar();

        while( !(c>='0' && c<='9') ){
            ptr[0]=c;
            strcat( arr[i].name , ptr );
            c=getchar();
        }

        scanf( "%d%d" ,&arr[i].score1,&arr[i].score2 );
        arr[i].score1+=(c-'0')*10;
    }

    for(int i=0;i<n;i++){
        // printf( "%s\n" ,arr[i].name );
        printf( "%s\t%d\t%d\n",arr[i].id,arr[i].score1,arr[i].score2 );
    }

    float max=-1.0 , cur ;
    int idx=-1;

    for(int i=0;i<n;i++){
        cur = (float)(arr[i].score1)*0.4+(float)(arr[i].score2)*0.6;
        if( cur > max ){
            max = cur;
            idx=i;
        }
    }

    printf( "%s\t%d\n",arr[idx].name,(int)(max) );

    return 0;
}