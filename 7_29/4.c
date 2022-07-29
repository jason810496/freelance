#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
    return (a>b ? a:b);
}

int left(int i){
    return i*2+1;
}

int right(int i){
    return i*2+2;
}

int height(int *T ,int cur, int n){
    if( cur > n ) return 0;
    if( T[cur]==-1 ) return 0;

    return max( height(T,left(cur),n) , height(T,right(cur),n) )+1;
}
int main(){

    int n;
    scanf("%d" , &n);

    int T[n];

    // -1 stand for null 
    for(int i=0;i<n;i++){
        scanf("%d" , &T[i] );
    }

    printf("\nTree height : %d" , height(T , 0, n ) );
    return 0;
}