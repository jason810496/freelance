#include <stdio.h>

int main(){
    // 幾個輸入
    int n;
    scanf("%d" , &n );


    // 陣列開成 n 的大小
    int arr[n];
    // 依序讀入陣列
    for(int i=0;i<n;i++){
        scanf("%d" , & arr[i] );
    }


    // 進行排序 
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if( arr[j] < arr[i] ){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // eg : 1 7 8 2 5 3 9
    // 排序後 : 1 2 3 5 7 8 9 


    int passscore = 60;
    int NotPass=arr[0] , Pass=arr[n-1];
    // NotPass : 1 , Pass : 9
    // arr[0] ： 陣列第一個值 （ 最小的值 ，因為經過排序了 ）
    // ar[n-1] : 陣列最後一個值 （ 最大的值 ，因為經過排序了 ）


    // 從陣列的最前端 
    // 0 11 33 55 61 70 90 
    // NotPass  : 0 
    for(int i=1;i<n;i++){
        if( arr[i] < passscore ){
            NotPass = arr[i];
        }
    }
    // final NotPass : 55


     // 從陣列的最後端 
    // 0 11 33 55 61 70 90 
    // Pass  : 90 
    for(int i=n-1; i>=0 ;i--){
        if( arr[i] > passscore ){
            Pass = arr[i];
        }
    }
    // final Pass = 61


    // 剛好班上有及格跟沒有及格的
    if( NotPass<passscore && Pass>passscore ){
        printf("%d %d\n" , NotPass , Pass );
    }
    else if( Pass < passscore ){
        printf("全班都不及格\n");
    }
    else if( NotPass > passscore ){
        printf("全班都集格 %d\n" , NotPass );
    }
    return 0;
}