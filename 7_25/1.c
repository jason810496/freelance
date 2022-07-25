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

void FindRecursionMax(int *data ,int n ,int cur,int *index,int *value){
    if( cur>=n ) return;

    if( data[cur] > *value ){
        *value = data[cur];
        *index = cur; 
    }

    FindRecursionMax(data , n , cur+1 , index , value );
    return;
}

int main(){
    
    int n ; 
    scanf("%d" , &n );

    int *data = malloc( n * sizeof(int) ) ;

    for(int i=0;i<n;i++){
        scanf("%d" , &data[i]);
    }

    FindMax( data , n );

    int idx=0 , val=-1;
    FindRecursionMax( data , n , 0 , &idx , &val );
    printf("最大值為 data[%d] = %d\n" , idx , val );
    return 0;
}