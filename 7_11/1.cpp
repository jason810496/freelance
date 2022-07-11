#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Q1(){
    int cur , sum=0 ,cnt=0;
    printf("Q1 input:\n");

    while( scanf("%d", &cur) && cur!=-99 ){
        sum+=cur;
        cnt++;
    }

    printf("Q1 output:\n");
    printf("sum = %d\n average = %f\n" , sum  , (float)sum/(float)cnt);
}

void Q2(){
    int n ; 
    printf("Q2 input:\n");
    scanf("%d",&n);
    int ans =1 ;
    for(int i=0;i<n;i++){
        ans<<=1;
    }
    printf("Q2 output: 2^%d= %d\n", n , ans );
}

void Q3(){
    int num , ans=0;
    printf("Q3 input : \n");
    scanf("%d" , &num );
    while(num){
        num/=10;
        ans++;
    }
    if( ans>1 )printf("Q3 output: %d digitals" , ans );
    printf("Q3 output : 1 digital \n");
}

int main(){
    Q1();
    Q2();
    Q3();
    return 0;
}