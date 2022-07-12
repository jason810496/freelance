#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n , i , bit[15] = {};
    scanf("%d" , &n);
    for( i=0;n;n>>=1 , i++){
        bit[i]=n&1;
    }
    for(int j=i-1;j>=0;j--){
        printf("%d",bit[j]);
    }
    return 0;
}