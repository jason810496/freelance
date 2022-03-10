#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
  int x;
  int y;
} point2d;

// generic swap
// assumption: the memory segments don't overlap
void swap(void* a, void* b, size_t s)  {
  char* char_a = (char*)a;
  char* char_b = (char*)b;

  for (int i=0;i<s;i++) {
    char tmp = char_a[i];
    char_a[i] = char_b[i];
    char_b[i] = tmp;
  }

/* // ALTERNATIVE, requires extra space
  void* tmp = malloc(s);
  memcpy(tmp, a, s);
  memcpy(a, b, s);
  memcpy(b, tmp, s);
  free(tmp);
*/
  }
int cmpr_norm(const void* a, const void* b){
  return (abs(((point2d*)a)->x)+abs(((point2d*)a)->y))-(abs(((point2d*)b)->x)+abs(((point2d*)b)->y));
}
int cmpr_x(const void* a, const void* b){
  return ((point2d*)a)->x-((point2d*)b)->x;
}
int cmpr_y(const void* a, const void* b){
  return ((point2d*)a)->y-((point2d*)b)->y;
}
// if compare (a,b)<0, then a must come before b in the sorted array
// if compare (a,b)>0, then a must come after b in the sorted array
int gen_insertion_sort(void* arr, int n, size_t s, int (*compare)(const void*, const void*)) {

  int cnt=0 , *ar = arr;

  
  for(int i=1 ; i<n ;i++){
      int cur=ar[i] , j=i-1;

      while (compare(&cur, (ar+j) )<0 && j>=0) {
        swap( (ar+j+1) , (ar+j) , sizeof(int) );
        cnt++;
        j--;
      }
      ar[j+1] = cur ;
  }

  return cnt;
}  


// used for test test_q2_2
// sort points by the x-coordinate
// and if the x-coordinates are equal, sort by the y-coordinate


int cmpr_points_L2(const void* a, const void* b) {
  point2d pt1 = *(const point2d*) a;
  point2d pt2 = *(const point2d*) b;
  if (pt1.x != pt2.x)
    return (pt1.x-pt2.x);
  else // pt1.x == pt2.x
    return (pt1.y-pt2.y);
}

// void Print_arrvoid* arr, int n, size_t s){
    
// }




bool test_q2_2()  {
  int len = 5;
  point2d ar[5] = {{2,0}, {0,-6}, {5,3}, {3,4}, {3,0}};

  int swaps = gen_insertion_sort(ar, len, sizeof(point2d), cmpr_points_L2);
  //          [{2,0}, {0,-6}, {5,3}, {3,4}, {3,0}] 0
  // {0,-6}:  [{0,-6}, {2,0}, {5,3}, {3,4}, {3,0}] +1
  // {5,3} :  [{0,-6}, {2,0}, {5,3}, {3,4}, {3,0}] 0
  // {3,4} :  [{0,-6}, {2,0}, {3,4}, {5,3}, {3,0}] +1
  // {3,0} :  [{0,-6}, {2,0}, {3,0}, {3,4}, {5,3}] +2
  
  point2d correct_ans[5] = {{0,-6}, {2,0}, {3,0}, {3,4}, {5,3}};

  printf( "sizeof 2d %zu , int %zu",sizeof(point2d) , sizeof(int));
  bool okFlag = true;
  for (int i=0;i<len;i++)
    if (ar[i].x != correct_ans[i].x || ar[i].y != correct_ans[i].y)
      okFlag = false;


  if (okFlag && swaps==4) {
    printf("Q2-2 ok\n");
    return true;
  }
  else  {
    printf("Q2-2 ERROR\n");
    return false;
  }
}

int main()  {

  test_q2_2();
  
  return 0;
}