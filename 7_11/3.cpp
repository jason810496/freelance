#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int num , ans=0;
    printf("Q3 input : \n");
    scanf("%d" , &num );
    while(num){
        num/=10;
        ans++;
    }
    if( ans>1 )printf("Q3 output: %d digitals" , ans );
    printf("Q3 output : 1 digital \n");
    return 0;
}