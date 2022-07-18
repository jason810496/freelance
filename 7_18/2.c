#include <stdio.h>

int main(){
    int n=7 , arr[7] = {} , sum=0;

    for(int i=0;i<n;i++){
        scanf("%d" , &arr[i] );
        sum+=arr[i];
    }

    float avg=(float)(sum)/(float)(n);
    printf("Average = %.1f\n" , avg );

    // sort

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if( arr[i]>arr[j] ){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Median = %d\n" , arr[n/2] );

    int bucket[7] = { } , flag[7] = { };

    for(int i=0 , cur ;i<n;i++){
        if( flag[i]>0 ) continue;
        flag[i] = i+1;
        bucket[i]++;
        for(int j=i+1 ; j<n ; j++){
            if( flag[j]>0 ) continue;
            if( arr[i] == arr[j] ){
                flag[j] = flag[i];
                bucket[i]++;
            }
        }
    }

    int max=1 , idx=-1;
    for(int i=0;i<n;i++){
        if( bucket[i]>max ){
            max = bucket[i];
            idx = flag[i]-1;
        }
    }
    
    printf("Mod = ");
    if( max==1 ) printf("None");
    else printf("%d" , arr[idx] );

    return 0;
}