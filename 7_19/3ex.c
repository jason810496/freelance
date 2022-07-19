#include <stdio.h>

int main(){

    // 開夠大的陣列 ( 夠大的線段 )
    int arr[1001] = { };  

    int n , L , R ,ans=0 , cur=0;
    scanf( "%d" , &n );
    for(int i=0;i<n;i++){
        // L : Left 
        // R : Right 
        scanf("%d%d" , &L , &R );

        // [ L ,R )
        for(int j=L ; j<R;j++){
            arr[j]+=1;
        }
    }  

    // 重新掃過一遍大陣列
    for(int i=1;i<=1000;i++){
        
        if( arr[i]>0 ){
            ans+=1;
        }
    }

    printf("%d" , ans );
    return 0;
}

