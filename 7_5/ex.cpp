#include <stdio.h> 
#include <conio.h> 

int main()
{
  int ch;

  puts ("Press any key, q to quit");  
  
  while ((ch = getch()) != EOF && ch != 'q')
    printf ("%c\n", ch);

  return 0;
}