#include <stdio.h>
#include <stdlib.h>


void FindMax(int *data , int n ){

    int index=0 , value = data[0];

    for(int i=1 ; i<n;i++){
        if( data[i] > value ){
            value = data[i];
            index = i;
        }
    }

    printf("最大值為 data[%d] = %d\n" , index , value );
}

void FindRecursionMax(int *data ,int n ,int current,int* index,int* value){
    if( current==n ) return;

    if( data[ current ] > *value ){
        *value = data[ current ];
        *index = current; 
    }

    FindRecursionMax(data , n , current+1 , index , value );
    return;
}

int main(){
    
    int n ; 
    scanf("%d" , &n );

    int *data = (int*)malloc( n * sizeof(int) ) ;

    for(int i=0;i<n;i++){
        scanf("%d" , &data[i]);
    }

    FindMax( data , n );

    int idx=0 , val=data[0];
    FindRecursionMax( data , n , 1 , &idx , &val );

    printf("最大值為 data[%d] = %d\n" , idx , val );

    return 0;
}