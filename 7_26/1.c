#include <stdio.h>
#include <stdlib.h>

int Convert(int binaryCode,int n){
    if( !binaryCode ) return 0;

    int lastBit = (binaryCode%10) , base=1;
    for(int i=0;i<n;i++){
        base = base*2;
    }
    return Convert(binaryCode/10,n+1)+lastBit*base;
}

int main(){
    
    int n ; 
    scanf("%d" , &n );

    while( n != -1 ){
        printf("Dec : %d\n" , Convert(n,0) );
        scanf("%d" , &n);
    }
    return 0;
}