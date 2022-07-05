#include <stdio.h> 
// #include <windows.h> 
// #include<beep.c>
#include<unistd.h>

#define DO 523
  
int main() 
{ 
    char c;
    c=getc();
    
    while( c!=EOF ){
        printf("%c\n" , c);
        c=getc();
    }
    return 0; 
}
