#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assignment3.h"

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
void sort_points(point2d* ar, int n) {
  qsort(ar,n,sizeof(point2d),cmpr_norm);
  for(int i=0; i<n; i++){
    printf("{%d,%d}",ar[i].x,ar[i].y);
  }
  printf("\n");
  int i=0;
  int j=0;
  int k=0;
  while(i<n){
    while(abs(ar[i].x)+abs(ar[i].y)==abs(ar[i+j].x)+abs(ar[i+j].y)){
      j++;
    }
    printf("j=%d\n",j);
    printf("  xqsort executed from {%d,%d} to {%d,%d}\n",ar[i].x,ar[i].y,ar[i+j-1].x,ar[i+j-1].y);
    qsort(ar+i,j,sizeof(point2d),cmpr_x);
    for(int i=0; i<n; i++){
      printf("  {%d,%d}",ar[i].x,ar[i].y);
    }
    printf("\n");
    i=i+j;
  }
  i=0;
  while(i<n){
    printf("i=%d\n",i);
    k=0;
    while(abs(ar[i].x)+abs(ar[i].y)==abs(ar[i+k].x)+abs(ar[i+k].y)&&ar[i].x==ar[i+k].x){
      k++;
    }
    printf("k=%d\n",k);
    printf("yqsort executed from {%d,%d} to {%d,%d}\n",ar[i].x,ar[i].y,ar[i+k-1].x,ar[i+k-1].y);
    qsort(ar+i,k,sizeof(point2d),cmpr_y);
    for(int i=0; i<n; i++){
      printf("{%d,%d}",ar[i].x,ar[i].y);
    }
    printf("\n");
    i=i+k;
  }
  printf("\n");
}  

// if compare (a,b)<0, then a must come before b in the sorted array
// if compare (a,b)>0, then a must come after b in the sorted array
int gen_insertion_sort(void* arr, int n, size_t s, int (*compare)(const void*, const void*)) {

  int cnt=0 ;
  if( s==4){
    int *ar=arr;
    for(int i=1 ; i<n ;i++){
      int cur=ar[i] , j=i-1;

      while (compare(&cur, (ar+j) )<0 && j>=0) {
        swap( (ar+j+1) , (ar+j) , s);
        cnt++;
        j--;
      }
      ar[j+1] = cur ;
    }
  }
  else{
    point2d *ar=arr;
    for(int i=1 ; i<n ;i++){
      point2d cur=ar[i];
      int j=i-1;

      while (compare(&cur, (ar+j) )<0 && j>=0) {
        swap( (ar+j+1) , (ar+j) , s );
        cnt++;
        j--;
      }
      ar[j+1] = cur ;
    }
  }

  return cnt;
}  


int find(int* A, int start, int end, bool (*pred)(int)) {
  // implement me
  return -1;
}  


int count(int* A, int start, int end, bool (*pred)(int)) {
  // implement me
  return -1;
}  


void map(int* A, int start, int end, int (*f)(int)) {
  // implement me
}  


int reduce(int* A, int start, int end, int (*f)(int,int)) {
  // implement me
  return -1;
}  
