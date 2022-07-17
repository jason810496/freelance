#include <stdio.h>

int stack[20] = { } , size=0;

int main(){
    int n  , cur ; 
    scanf("%d" , &n);

    for(int i=0 , j=0 ; i<n ; i++ ){

        scanf("%d" , &cur );
        if( i==0 ){
            stack[ size++ ] = cur;
            continue;
        }

        if( cur == stack[ size-1] ){
            size--;
        }
        else{
            stack[ size++ ] = cur;
        }
    }
    
    int ans=0;

    for(int i=0; size ;i++ , size--){
        ans+=stack[i];
    }

    printf("%d" , ans );
    return 0;
}