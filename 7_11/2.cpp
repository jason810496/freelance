#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n ; 
    printf("Q2 input:\n");
    scanf("%d",&n);
    int ans =1 ;
    for(int i=0;i<n;i++){
        ans<<=1;
    }
    printf("Q2 output: 2^%d= %d\n", n , ans );
    return 0;
}