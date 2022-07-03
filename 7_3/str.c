#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main() {

    char str[105]={};
    int st ,len ,size ,cnt=0,bucket[256]={};

    scanf("%s%d%d" , str , &st,&len);
    
    while( 'a'<=str[cnt]&&'z'>=str[cnt] || 'A'<=str[cnt]&&'Z'>=str[cnt] ){
        cnt++;
    }
    size = cnt;

    // printf("size %d\n" , size );
    for(int i=0;i<size;i++){
        bucket[ str[i] ]++;
    }
    for(int i=0 , idx=0;i<256;i++){
        while( bucket[i] ){
            str[idx++] = (char)(i);
            bucket[i]--;
        }
    }
    // printf("%s\n" , str);

    for( int i=0;i<size;i++){
        // printf("%d" , i);
        if( (i>=st) && (i<=st+len-1) ) continue;
        // printf("%d" , i);
        printf("%c" , str[i]);
    }
    printf("\n");
    return 0;
}