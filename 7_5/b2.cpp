#include <stdio.h>

#define DO 523
int main(){

    char c ;

    while( c=getchar()  && c!=EOF ){
        if( c=='1' ) {
            printf("w\n");
        }

        c = getchar();
    }
    
    return 0;
}