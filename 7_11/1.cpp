#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int cur , sum=0 ,cnt=0;
    printf("Q1 input:\n");

    while( scanf("%d", &cur) ){
        if( cur == -99 ) break;
        sum+=cur;
        cnt++;
    }

    printf("Q1 output:\n");
    if( cnt==0 ){
        printf("invalid testcase\n");
        return 0;
    }
    printf("sum = %d\n average = %f\n" , sum  , (float)sum/(float)cnt);
    return 0;
}