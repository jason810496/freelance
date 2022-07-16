#include <stdio.h>

int main()
{   int m,n,num,row=0,col=0,num1,col1;
    
    scanf("%d %d",&m,&n);
    
    int arr[m][n];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
   
   for(int i=0;i<n;i++){
       
       num = arr[i][0];  
       
       for(int j=0;j<m;j++){      //find min in row i  
           if (num >= arr[i][j]){
               num = arr[i][j];
               col = j;
            }
                
        }
       int k;
       for(k=0;k<m;k++){
           if(num < arr[k][col])
              break;
        }
        if(k == m){
            num1 = num;
            //row = k;
        }
            //row = k;
       // printf("%d %d %d\n",num1,row,col);
    }
    
    printf("矩陣 B 為 :\n");    //output
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    printf("鞍點為 : B[%d][%d] = %d",row,col,num1);

    return 0;
}

/*



3 3    
1 2 123 54 78 65 32 12 35



*/