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

    printf("最大值為 data[%d] = %d" , index , value );
}

int main(){
    
    int n ; 
    scanf("%d" , &n );

    int *data = malloc( n * sizeof(int) ) ;

    for(int i=0;i<n;i++){
        scanf("%d" , &data[i]);
    }

    FindMax( data , n );
    return 0;
}