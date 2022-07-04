#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    //  1.
    float val;
    printf("input a floating point: ");
    scanf("%f" , &val);
    // printf("%f\n" , val );
    printf("value = %d\n" , (int)(val+0.5) );

    // 2.
    int kg;
    float pound;
    printf("input your weight(kg): ");
    scanf("%d" , &kg);
    
    pound = (float)kg * 2.2;
    printf("Your weight = %d pounds\n" , (int)(pound+0.5) );

    
    // 3.
    int cm , inches , feet ;
    // 1 foot  = 12*2.54 = 30.48 cm;
    printf("input your height(cm): ");
    scanf("%d" , &cm );
    feet = (double)cm / 30.48 ;
    inches = ( (double)cm - (double)feet*30.48 ) / 2.54 +0.5;
    printf("Your height = %d feet %d inches\n" , feet , inches );

    

    // 4.
    int arr[3] , sum=0;
    printf("input three integers: ");
    for(int i=0;i<3;i++){
        scanf("%d" , &arr[i] );
        sum+=arr[i];
    }
    printf("Average[%d,%d,%d] = %.2f\n" , arr[0] , arr[1] ,arr[2] , (float)(sum)/3.0);


   // 5.

   int x1 , y1 , x2 , y2;
   printf("input coordinate (x1,y1) (x2,y2) : " );
   scanf("%d%d%d%d", &x1 , &y1 , &x2 , &y2);
   float dx=(x1-x2) , dy=(y1-y2);
   printf("Distance = %.2f\n" , sqrt(dx*dx+dy*dy) );

    return 0;
}