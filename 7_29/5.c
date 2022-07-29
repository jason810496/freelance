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

int second(int *T ,int smallest ,int Mx,int cur, int n){
    if( cur > n ) return Mx;
    if( T[cur]==-1 ) return Mx;

    if( T[cur] > smallest && T[cur]<Mx){
        Mx = T[cur];
    }
    
    second(T,smallest,Mx,left(cur),n);
    second(T,smallest,Mx,right(cur),n);
}
int main(){

    int n;
    scanf("%d" , &n);

    int T[n];

    // -1 stand for null 
    for(int i=0;i<n;i++){
        scanf("%d" , &T[i] );
    }

    int ans = second(T , T[0], 100000 , 0, n ) , INF = 100000;
    printf("\nsecond : %d" , (ans==INF ? -1: ans )  );
    return 0;
}