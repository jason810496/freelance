#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
  int x;
  int y;
} point2d;

/* Question 1 */

// sorts an array of points using qsort
void sort_points(point2d* ar, int n);


/* Question 2 */

// InsertionSort algorithm for arrays of a generic type
// the function gets an array of length n of objects of given size
// it also get a compare function
// and sorts the array using the compare function
// the function returns the number of swaps made by the algorithm
// About compare()
int gen_insertion_sort(void* ar, int n, size_t size, int (*compare)(const void*, const void*));



/* Question 3 */


// The function gets an array A, two indices of the array, and a boolean predicate pred.
// It returns the smallest index i  in [start...end], such that pred(A[i])==true.
// If there is no index i in [start...end] with pred(A[i])==true, the function returns -1.
// Assumption start<=end.
int find(int* A, int start, int end, bool (*pred)(int));

// The function gets an array A, indices start <= end, and a boolean predicate pred.
// It returns the number of indices i in [start...end], such that pred(A[i])==true.
// Assumption start<=end.
int count(int* A, int start, int end, bool (*pred)(int));


// The function gets an array A, two indices of the array, and a function f.
// It applies f to each element A[i] with i  in [start...end].
// Assumption start<=end.
void map(int* A, int start, int end, int (*f)(int));


// The function gets an array A of ints, two indices of the array, and a function f.
// The function f works as follows:
// Start with accumulator = A[start]
// For i=start+1...end  compute accumulator=f(accumulator, A[i])
// Return accumulator
// For example, if f computes the sum of the two inputs,
// then reduce() will compute the sum A[start] + A[start+1] +...+A[end].
// Assumption start<=end.
int reduce(int* A, int start, int end, int (*f)(int,int));



#endif