#include <stdio.h>

int main(){
    // r : row 行, c : column 列
    int r ,c ,n ;
    scanf("%d%d%d" , &r , &c , &n );


    int max=r;
    if( c>r ) max=c;
    // max : max( r , c ) 
    int arr[max][max] , arr2[max][max];


    int q , curR=r , curC=c;
    // 輸入陣列 
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d" , &arr[i][j] );
        }
    }

    for(int k=0;k<n;k++){
        // 0: +180 , 1: +90
        scanf("%d" , &q );

        if( q==0 ){ // 0 : +180 
            // 看成 : 把原先陣列 上下顛倒的感覺 
            for(int i=0;i<=curR/2;i++){
                for(int j=0;j<curC;j++){
                    // 上面的元素跟下面的元素做交換
                    int temp = arr[i][j];
                    arr[i][j] = arr[curR-i-1][j];
                    arr[curR-i-1][j] = temp;
                }
            }
        }
        else if( q==1 ){ // 1 : +90 

            // eg : 3x2 --(+90)--> 2x3 
            // curR : current row 3
            // curC : current column 2
            // newR : new row 2
            // newC : new column 3
            int newR = curC , newC = curR;


            // 做 +90度旋轉的步驟 
            for(int i=0;i<curR;i++){
                for(int j=0;j<curC;j++){
            // Original : ( i,j ) -> New ( j,NewRow-i-1 )
                    arr2[j][ curR-i-1 ] = arr[i][j];
                }
            }


            // 旋轉過後的陣列抄回原本的陣列 
            curR = newR;
            curC = newC;
            for(int i=0;i<curR;i++){
                for(int j=0;j<curC;j++){
                    arr[i][j] = arr2[i][j];
                }
            }
            
            // +90度旋轉結束
        }
    }

    // 輸出
    for(int i=0 ; i<curR ; i++){
        for(int j=0;j<curC;j++){
            printf("%d " , arr[i][j] );
        }
        printf("\n");
    }

    return 0;
}

/*
3 2 3 
1 1 
1 3
2 1
0 1 1
*/