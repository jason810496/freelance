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

    switch (c){
        case '1':
            Beep( DO , 500);
            break;
    }
  }

  system ("/bin/stty cooked");
  return 0;
}