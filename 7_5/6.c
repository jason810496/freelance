#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Q1(){
    char c;
    printf("Q1:\ninput: ");
    scanf("%c" , &c);
    printf("output:\n");

    switch ( c ){
        case 'A'...'Z':
            printf("alphabet\n");
            break;
        case 'a'...'z':
            printf("alphabet\n");
            break;
        case '0'...'9':
            printf("digital\n");
            break;
    
        default:
            printf("special\n");
    }
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
    switch ( num>=0 ){
        case 1:
            printf("%d\n" , num );
            break;
        default:
            printf("%d" , -num );
    }
}

void Q4(){
    int year;
    printf("Q3:\ninput: ");
    scanf("%d" , &year);
    printf("output:\n");
    int flag = year%400==0 || (year%100!=0 && year%4==0);

    switch ( flag ){
        case 1:
            printf("leap year\n");
            break;
        default:
            printf("common year\n");
    }
}
int main(){
    
    // Q1();
    // Q2();
    // Q3();
    // Q4();

    return 0;
}