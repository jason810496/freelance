#include <stdio.h>

int main(){
    int r=4 , c=4 , cur, arr[4][4]={};
    for(int i=15 ; i>=0 ; i--){
        scanf("%d" , &cur );
        arr[i/4][i%4] = cur;
        // 用 column major 的想法
        // 如 i=15 -> ( 15/4 , 15%4) = ( 3 , 3)
        //   i=14 -> ( 14/4 , 14%4) = ( 3 ,2 )
        // 剛好會是反向輸入陣列
    }

    // 最後將陣列結果輸出
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d " , arr[i][j] );
        }
        printf("\n");
    }
    return 0;
}