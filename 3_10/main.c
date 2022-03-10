#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "assignment3.h"

/* Question 1 */

/*
bool test_q1_1()  {
  int len = 7;
  point2d A[] = {{3,2}, {7,1}, {1,1}, {-3,4}, {-5,0}, {-6,2}, {-3,4}};
  point2d correct_ans[] = {{1,1}, {-5,0}, {3,2}, {-3,4}, {-3,4}, {-6,2}, {7,1}};


//  for(int i=0;i<len;i++) printf("(%d, %d) ", A[i].x, A[i].y);
//  printf("---\n");

  sort_points(A,len);

//  for(int i=0;i<len;i++) printf("(%d, %d) ", A[i].x, A[i].y);
//  printf("---\n");


  bool okFlag = true;

  for (int i=0;i<len;i++)
    if (A[i].x!=correct_ans[i].x || A[i].y!=correct_ans[i].y) {
      okFlag = false;
    }

  if (okFlag)  {
    printf("Q1-1 ok\n");
    return true;
  }
  else  {
    printf("Q1-1 ERROR\n");
    return false;
  }
}


bool test_q1_2()  {
  int len = 8;
  point2d A[] = {{3,2}, {3,2}, {3,-2}, {4,-1}, {5,0}, {-3,-2},  {-3,2}, {5,0}};
  point2d correct_ans[] = {{-3,-2}, {-3,2}, {3,-2}, {3,2}, {3,2}, {4,-1}, {5,0}, {5,0}};

//  for(int i=0;i<len;i++) printf("(%d, %d) ", A[i].x, A[i].y);
//  printf("---\n");

  sort_points(A,len);
//  for(int i=0;i<len;i++) printf("(%d, %d) ", A[i].x, A[i].y);
//  printf("---\n");

  bool okFlag = true;

  for (int i=0;i<len;i++)
    if (A[i].x!=correct_ans[i].x || A[i].y!=correct_ans[i].y) {
      okFlag = false;
    }

  if (okFlag)  {
    printf("Q1-2 ok\n");
    return true;
  }
  else  {
    printf("Q1-2 ERROR\n");
    return false;
  }
}

*/


/* Question 2 */


// used for test test_q2_1 for sorting in reverse order
// int cmpr_ints_rev(const void* a, const void* b) {
//   return *(const int*)b - *(const int*)a;
// }

int cmpr_ints_rev(const void* a, const void* b) {
  return *(const int*)b - *(const int*)a;
}

bool test_q2_1()  {
  
  int len = 6;
  int ar[6] = {7,3,5,1,11,9};
  
  // cmpr_ints_rev sorts the array in reverse order
  int swaps = gen_insertion_sort( ar, len, sizeof(int) , cmpr_ints_rev);
  // 7 : [7,3,5,1,11,9]  0
  // 3 : [7,3,5,1,11,9]  0
  // 5 : [7,5,3,1,11,9] +1
  // 1 : [7,5,3,1,11,9]  0
  //11 : [11,7,5,3,1,9] +4
  //11 : [11,9,7,5,3,1] +4
  

//   printf(" swap : %d" , swaps );

  bool okFlag = true;
  for (int i=0;i<len;i++)
    if (ar[i] != 11-2*i)
      okFlag = false;


  if (okFlag && swaps==9) {
    printf("Q2-1 ok\n");
    return true;
  }
  else  {
    printf("Q2-1 ERROR\n");
    return false;
  }
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

  bool okFlag = true;
  for (int i=0;i<len;i++)
    if (ar[i].x != correct_ans[i].x || ar[i].y != correct_ans[i].y)
      okFlag = false;

  for(int i=0;i<5;i++){
    printf(" x: %d ,y: %d\n" , ar[i].x , ar[i].y);
  }

  if (okFlag && swaps==4) {
    printf("Q2-2 ok\n");
    return true;
  }
  else  {
    printf("Q2-2 ERROR\n");
    return false;
  }
}



/* Question 3 */


// used for  test_q3_find and test_q3_count

/*
bool is_even(int x) { return x%2 == 0; }
bool is_positive(int x) { return x>0; }

bool test_q3_find()  {
  int A[6] = {-1,-3,-6,5,2,7};

  if (find(A, 0, 5, is_even)==2 && find(A, 0, 2, is_positive)==-1) {
    printf("Q3-find ok\n");
    return true;
  }
  else  {
    printf("Q3-find ERROR\n");
    return false;
  }
}


bool test_q3_count()  {
  int A[6] = {-1,3,-6,5,2,7};

  if (count(A, 0, 5, is_even)==2 && count(A, 2, 5, is_positive)==3) {
    printf("Q3-count ok\n");
    return true;
  }
  else  {
    printf("Q3-count ERROR\n");
    return false;
  }
}

*/

// used for test test_q3_map

/*
int square(int x) { return x*x;}

bool test_q3_map()  {
  int A[6] = {-1,3,-6,5,2,7};
  map(A, 1, 5, square); // apply only to indices 1...5

  if (A[0]==-1 && A[1]==9 && A[3]==25 && A[5]==49) {
    printf("Q3-map ok\n");
    return true;
  }
  else  {
    printf("Q3-map ERROR\n");
    return false;
  }
}
*/

// used for test test_q3_reduce

/*
int sum(int x, int y) {return x+y;}
int max(int x, int y) {return x>y?x:y;}

bool test_q3_reduce()  {
  int A[6] = {10,3,-6,5,2,7};

  if (reduce(A, 0, 5, sum)==21 && reduce(A, 1, 5, max)==7) {
    printf("Q3-reduce ok\n");
    return true;
  }
  else  {
    printf("Q3-reduce ERROR\n");
    return false;
  }
}

*/


// when testing your code, it may be convenient 
// to comment out some of the test cases
// and focus only on the one you are working on right now.
// Also, you are encouraged to add more test casess
int main()  {

  // test_q1_1();
  // test_q1_2();

//   test_q2_1();
  test_q2_2();

  /*
  test_q3_count();
  test_q3_find();
  test_q3_map();
  test_q3_reduce();
  */
  
  return 0;
}