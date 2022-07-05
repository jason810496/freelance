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


int cmp(const void *a , const void *b){
    return *(int*)a-*(int*)b;
}
void Q5(){
    int arr[3];
    printf("Q5:\ninput: ");
    for(int i=0;i<3;i++){
        printf("input %d side :\n" , i+1 );
        scanf("%d" , &arr[i] );
    }
    printf("output:\n");
    
    qsort(arr,3,sizeof(int) , cmp);

    if( arr[0]+arr[1] > arr[2] ) printf("valid\n");
    else printf("not valid\n");
}

void Q6(){
    printf("Q6:\ninput: ");
    float ht , wt;
    printf("input height(M): ");
    scanf("%f" , &ht );
    printf("input weight(Kg): ");
    scanf("%f" , &wt );
    printf("output:\n");

    float BMI =  wt/(ht*ht) ;
    printf("BMI : %.2f" ,BMI ) ;
    
    if( BMI < 18.5 ) printf("underweight\n");
    else if( BMI<24 ) printf("normal\n");
    else printf("overweight\n");
}
int main(){
    
    // Q1();
    // Q2();
    // Q3();
    // Q4();
    Q5();

    return 0;
}