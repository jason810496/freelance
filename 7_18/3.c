#include <stdio.h>

int main(){
    // 本題與合併排序中的合併過程相同
    int x[5] , y[5] , z[10] , n=5;

    for(int i=0;i<n;i++){
        scanf("%d" ,&x[i] );
    }
    for(int i=0;i<n;i++){
        scanf("%d" ,&y[i] );
    }

    int i=0,j=0,k=0;

    while( i<n && j<n ){
        // 拿 x 與  y 陣列最前端的元素來見查
        // 取較小的填入 z 陣列 
        if( x[i]<=y[j] ){
            z[k++] = x[i++];
        }
        else{
            z[k++] = y[j++];
        }
    }

    // 如果 x 陣列還有剩 ， 把剩下的填入 z 
    while( i<n ){
        z[k++] = x[i++];
    }

    // 如果 y 陣列還有剩 ， 把剩下的填入 z 
    while( j<n ){
        z[k++] = y[j++];
    }

    for(int i=0;i<10;i++){
        printf( "%d " ,z[i] );
    }
    return 0;
}