#include <stdio.h>

int main()
{   int m,n;
    
    scanf("%d %d",&m,&n);
    
    int arr[m][n];

    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }

    printf("矩陣 B 為 :\n");    //output
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
   

    printf("鞍點為 :\n");

    int rowMin[n] , colMax[m];
    for(int i=0;i<n;i++){
        rowMin[i] = arr[i][0];
        for(int j=1;j<m;j++){
            if( arr[i][j]<rowMin[i] ) rowMin[i] = arr[i][j];
        }
    }

    for(int j=0;j<m;j++){
        colMax[j] = arr[0][j];
        for(int i=1;i<n;i++){
            if( arr[i][j]>colMax[j] ) colMax[j] = arr[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(  rowMin[i] == colMax[j] ){
                printf("B[%d][%d] = %d\n" , i,j,rowMin[i] );
            }
        }
    }
    return 0;
}