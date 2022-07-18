#include <stdio.h>

int main(){
    int n=6; 
    double arr[6] , accurate ;

    for(int i=0;i<n;i++){
        scanf("%lf" , &arr[i] );
    } 
    accurate = arr[0];

    for(int i=1;i<n;i++){
        float gap=accurate - arr[i];
        if( gap<0 ) gap=-gap;
        if( gap > 1.0 ){
            if( accurate>arr[i] ){
                while( gap > 5.0 ){
                    arr[i]*=10.0;
                    gap = accurate - arr[i];
                    if( gap<0 ) gap=-gap;
                }
            }
            else{
                while( gap > 5.0 ){
                    arr[i]/=10.0;
                    gap = accurate - arr[i];
                    if( gap<0 ) gap=-gap;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%.2lf ", arr[i] );
    }
    return 0;
}