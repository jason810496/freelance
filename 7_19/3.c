#include <stdio.h>

int main(){

    int arr[1001] = { };  

    int n , L , R ,ans=0 , cur=0;
    scanf( "%d" , &n );
    for(int i=0;i<n;i++){
        scanf("%d%d" , &L , &R );
        arr[L]+=1;
        arr[R]-=1;
    }  

    for(int i=1;i<=1000;i++){
        cur+=arr[i];
        if( cur > 0 ){
            ans+=1;
        }
    }

    printf("%d" , ans );
    return 0;
}


/*

5
160 180
150 200
280 300
300 330
190 210

*/