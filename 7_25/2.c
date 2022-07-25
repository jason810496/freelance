#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int n=8 , m=8 , x,y;
    int map[n][m];

    scanf("%d%d" , &x , &y);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            map[i][j]=0;
        }
    }

    map[x][y]=-1;

    //直列
    for(int i=0;i<n;i++){
        if( i==x ) continue;
        map[i][y]=1; 
    }
    //橫列
    for(int j=0;j<m;j++){
        if( j==y ) continue;
        map[x][j]=1; 
    }

    int i,j;
    // 左上
    i=x-1;
    j=y-1;
    while( i>=0 && j>=0 ){
        map[i][j]=1;
        i--;
        j--;
    }
    // 左下
    i=x+1;
    j=y-1;
    while( i<n && j>=0 ){
        map[i][j]=1;
        i++;
        j--;
    }
    // 右上
    i = x-1;
    j = y+1;
    while( i>=0 && j<m ){
        map[i][j]=1;
        i--;
        j++;
    }
    // 右下
    i=x+1;
    j=y+1;
    while( i<n && j<m ){
        map[i][j]=1;
        i++;
        j++;
    }

    //輸出
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( map[i][j]>0 ) {
                printf("1");
            }
            else if( map[i][j]<0 ){
                printf("Q");
            }
            else{
                printf(" ");
            }
        }

        printf("\n");
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         printf("%d" , map[i][j] );
    //     }
    //     printf("\n");
    // }
    
    return 0;
}