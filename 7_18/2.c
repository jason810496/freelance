#include <stdio.h>

int main(){
    int n=7 , arr[7] = {} , sum=0;

    for(int i=0;i<n;i++){
        scanf("%d" , &arr[i] );
        sum+=arr[i];
    }

    // 計算平均
    float avg=(float)(sum)/(float)(n);
    printf("Average = %.1f\n" , avg );

    // bobble sort 
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if( arr[i]>arr[j] ){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // 中位數 = 排序完的陣列最中間的數 , index 剛好是 n/2 
    printf("Median = %d\n" , arr[n/2] );

    // bucket -> 這個數字出現過幾次
    // flag   -> 這個數字是否出現過（ 用 index+1 來表示
    int bucket[7] = { } , flag[7] = { };

    for(int i=0 , cur ;i<n;i++){
        // 這個數字已經出現過了 , 就跳過不用檢查
        if( flag[i]>0 ) continue;
        // 標記成自己的 index+1
        flag[i] = i+1;
        // 數量 +1 
        bucket[i]++;

        // 向陣列後方的元素檢查 
        for(int j=i+1 ; j<n ; j++){
            // 已經比標記過了 , 就跳過不用檢查
            if( flag[j]>0 ) continue;
            // 又遇到跟當前一樣的元素
            if( arr[i] == arr[j] ){
                // 一樣標記起來 , 數量+1
                flag[j] = flag[i];
                bucket[i]++;
            }
        }
    }


    int max=1 , idx=-1;
    for(int i=0;i<n;i++){
        // 找出數量>1 && 數量最多的 index 
        if( bucket[i]>max ){
            max = bucket[i];
            idx = flag[i]-1;
        }
    }
    
    printf("Mod = ");
    // 各出現一次 -> 沒有眾數
    if( max==1 ) printf("None");
    // 輸出眾數
    else printf("%d" , arr[idx] );

    return 0;
}