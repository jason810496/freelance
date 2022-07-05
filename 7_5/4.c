#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Q1(){
    char c;
    printf("Q1:\ninput: ");
    scanf("%c" , &c);
    printf("output:\n");
    if( ('a'<=c&&c<='z') || ('A'<=c&&c<='Z') ) printf("alphabet\n");
    else if( '0'<=c&&c<='9' ) printf("digital\n");
    else printf("special\n");
}

void Q2(){
    char c;
    const int gap = (int)('A')-(int)('a');
    printf("Q2:\ninput: ");
    scanf("%c" , &c);
    printf("output:\n");
    printf("%c\n" , (char)(c+gap) );
}

void Q3(){
    int num;
    printf("Q3:\ninput: ");
    scanf("%d" , &num);
    printf("output:\n");
    printf("%d" , (num <0 ? -num:num) );
}

void Q4(){
    int year;
    printf("Q3:\ninput: ");
    scanf("%d" , &year);
    printf("output:\n");
    if( year%400==0 || (year%100!=0 && year%4==0) ){
        printf("leap year\n");
    }
    else printf("common year\n");
}
int main(){
    
    Q1();
    Q2();
    Q3();
    Q4();

    return 0;
}