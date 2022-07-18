#include <stdio.h>

int main(){
    int n=6; 
    double arr[6] , accurate ;

    for(int i=0;i<n;i++){
        scanf("%lf" , &arr[i] );
    } 
    // 第一個一定是準確值
    accurate = arr[0];

    // 依序檢查剩下的元素
    for(int i=1;i<n;i++){
        // 計算絕對值差
        float gap=accurate - arr[i];
        // 值<0 取正
        if( gap<0 ) gap=-gap;

        // 絕對值差>1.0
        if( gap > 1.0 ){
            // 如果是元素太小
            if( accurate>arr[i] ){
                // 持續將元素 *10 直到絕對值差>5.0 ， （ 這邊因為浮點數誤差所以不取1.0 ， 改取 5.0 
                while( gap > 5.0 ){
                    // 一直 *10 
                    arr[i]*=10.0;
                    // 計算新的絕對值差
                    gap = accurate - arr[i];
                    if( gap<0 ) gap=-gap;
                }
            }
            else{
                while( gap > 5.0 ){
                    // 一直 /10
                    arr[i]/=10.0;
                    // 計算新的絕對值差
                    gap = accurate - arr[i];
                    if( gap<0 ) gap=-gap;
                }
            }
        }
    }

    // 印出更新過得陣列
    for(int i=0;i<n;i++){
        printf("%.2lf ", arr[i] );
    }
    return 0;
}