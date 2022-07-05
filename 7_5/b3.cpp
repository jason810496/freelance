#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <windows.h>
#include<unistd.h>

#define DO 523
int main(){
  char c;
  
  system ("/bin/stty raw");

  printf("press 1 to beep , q to quit\n");
  while((c=getchar())!= 'q') {
    // printf("%c\n" , c);
    if( c=='1' ){
        Beep(DO , 500);
    }
  }

  system ("/bin/stty cooked");
  return 0;
}