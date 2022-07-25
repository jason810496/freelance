#include <stdio.h>
#include <stdlib.h>


void FindMax(int *data , int n ){
    // data[0] , index -> 0 
    // data[1] , index -> 1 
    // data[2] , index -> 2

 
    // 陣列中第 N 個元素的值
    // data[ N-1 ] 

    int index=0 , value = data[0];

    // data[] = 2 1 7 8 3
    // index :  0 1 2 3 4

    // data[] = 5 4 3 2 1
    /*
        i=0 : index=0 , value=2 ( 初始值 )
        data[0]=2
        i=1 : index=0 , value=2
        data[1]=1
        i=2 : index=2 , value=7
        data[2]=7
        ...
    */
    for(int i=1 ; i<n;i++){
        if( data[i] > value ){
            value = data[i];
            index = i;
        }
    }

    printf("最大值為 data[%d] = %d\n" , index , value );
}

// data[] = 2 1 7 8 3
// index :  0 1 2 3 4
void FindRecursionMax(int *data ,int n ,int current,int* index,int* value){
    if( current==n ) return;

    if( data[ current ] > *value ){
        *value = data[ current ];
        *index = current; 
    }

    FindRecursionMax(data , n , current+1 , index , value );
    return;
}

/*

data[] : 1 2 3 
data[0]=1
data[1]=2
data[2]=3
   index

current : 0 
f ( cur=1 ){
    f ( cur=2) {
        f (cur=3){
            f ( cur=4){
                f{
                    if( current<=n ) return ;
                }
            }
        }
    }
}


*/

int main(){
    
    // 輸入 n 
    int n ; 
    scanf("%d" , &n );

    // 開動態記憶體 
    int *data = (int*)malloc( n * sizeof(int) ) ;


    for(int i=0;i<n;i++){
        scanf("%d" , &data[i]);
    }

    FindMax( data , n );

    int idx=0 , val=data[0];
    FindRecursionMax( data , n , 1 , &idx , &val );

    printf("最大值為 data[%d] = %d\n" , idx , val );

    return 0;
}