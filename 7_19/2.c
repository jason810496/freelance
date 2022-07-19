#include <stdio.h>

int main(){
    int r ,c ,n ;
    scanf("%d%d%d" , &r , &c , &n );

    int max=r;
    if( c>r ) max=c;
    int arr[max][max] , arr2[max][max];
    int oper , curR=r , curC=c;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf("%d" , &arr[i][j] );
        }
    }
    // 0 : +180 , 1: +90

    for(int k=0;k<n;k++){
        scanf("%d" , &oper );

        if( oper==0 ){
            for(int i=0;i<=curR/2;i++){
                for(int j=0;j<curC;j++){
                    int temp = arr[i][j];
                    arr[i][j] = arr[curR-i-1][j];
                    arr[curR-i-1][j] = temp;
                }
            }
        }
        else if( oper==1 ){
            int newR = curC , newC = curR;
            for(int i=0;i<curR;i++){
                for(int j=0;j<curC;j++){
                    arr2[j][ curR-i-1] = arr[i][j];
                }
            }

            curR = newR;
            curC = newC;
            for(int i=0;i<curR;i++){
                for(int j=0;j<curC;j++){
                    arr[i][j] = arr2[i][j];
                }
            }
            
        }
    }

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