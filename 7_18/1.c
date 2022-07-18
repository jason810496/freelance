#include <stdio.h>

int main(){
    int r=4 , c=4 , cur, arr[4][4]={};
    for(int i=15 ; i>=0 ; i--){
        scanf("%d" , &cur );
        arr[i/4][i%4] = cur;
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d " , arr[i][j] );
        }
        printf("\n");
    }
    return 0;
}