#include <stdio.h>

int main(){
    int x[5] , y[5] , z[10] , n=5;

    for(int i=0;i<n;i++){
        scanf("%d" ,&x[i] );
    }
    for(int i=0;i<n;i++){
        scanf("%d" ,&y[i] );
    }

    int i=0,j=0,k=0;

    while( i<n && j<n ){
        if( x[i]<=y[j] ){
            z[k++] = x[i++];
        }
        else{
            z[k++] = y[j++];
        }
    }

    while( i<n ){
        z[k++] = x[i++];
    }

    while( j<n ){
        z[k++] = y[j++];
    }

    for(int i=0;i<10;i++){
        printf( "%d " ,z[i] );
    }
    return 0;
}