/*Samir Cerrato
* COMP 211, Fall 2022, Wesleyan University
 * Homework #6
 *
 * Palindromes and sorting.
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "hw6.h"

/* palindrome_check(A, n) =
 *   true, where A[i] == A[n-1-i] for all i < (n-1-i)
 *   false otherwise
 *
 * Pre-conditions:
 */
bool is_palindrome(char A[]){
  int n = strlen(A);
  for(int i = 0; i < n/2; i++){
    if(A[i] == A[n-1-i]){
    }else{
        return false;
      }
    }
  return true;
}


/*  Insertion sort
 *
 */
void insertion_sort(int A[], int n){
  int i;
  int x;
  int key;

  for(i=1; i < n; i++){
    key = A[i];
    x = i-1;
    while(x >= 0 && A[x] > key){
      A[x+1] = A[x];
      x = x-1;
    }
    A[x+1] = key;
  }
}

/*  merge3: performs a 3-way merge
 *
 *  A is divided into 3 sub-arrays which are merged in sorted order
 *     -> lo:m1, m1:m2, m2:hi
 */
 /* After calling merge(A, m, B, n, C):
  * - C contains all the elements of A and B;
  * - C[0] <= ... <= C[m + n -1]
  *
  * Pre-conditions:
  * - A has size m and A[0] <= ... <= A[m-1].
  * - B has size n and B[0] <= ... <= B[n-1].
  * - C has size m + n.
  */

void merge3(int A[], int lo, int m1, int m2, int hi){
  int i = lo;
  int j = m1;
  int k = m2;
  int B[hi-lo];
  int x = 0;
  while(i < m1 && j < m2 && k < hi){
    if(A[i] <= A[j] && A[i] <= A[k]){
      B[x++]=A[i++];
      // i++;
      // x++;
    }else if(A[j] <= A[i] && A[j] <= A[k]){
        B[x++] = A[j++];
        // j++;
        // x++;
    }else {
        B[x++] = A[k++];
        // k++;
        // x++;
    }
  }
  while(i < m1 && j < m2) {
    if (A[i] <= A[j]) {
      B[x++] = A[i++];
      // i++;
      // x++;
    } else {
        B[x++] = A[j++];
        // j++;
        // x++;
    }
  }while(j < m2 && k < hi) {
    if (A[j] <= A[k]) {
      B[x++] = A[j++];
      // j++;
      // x++;
    } else {
        B[x++] = A[k++];
        // k++;
        // x++;
    }
  }
  while(i < m1 && k < hi) {
    if (A[i] <= A[k]) {
      B[x++] = A[i++];
      // i++;
      // x++;
    } else {
        B[x++] = A[k++];
        // k++;
        // x++;
    }
  }
  while(i < m1){
    B[x++]=A[i++];
    // i++;
    // x++;
  }
  while(j < m2){
    B[x++] = A[j++];
    // j++;
    // x++;
  }
  while(k < hi){
    B[x++] = A[k++];
    // k++;
    // x++;
  }
  for(int z=0; z < (hi-lo) ; z++){
    A[lo+z] = B[z];
  }
}


/*
 * Implements a recursive 3-way mergesort
 *   -> Divide array into thirds.
 *   -> Recursively sort each third.
 *   -> Merge thirds.
 */
void merge_sort3(int A[], int lo, int hi){
  int m1 = lo + (hi-lo) / 3;
  int m2 = lo + (2*(hi-lo) / 3);

  if ((hi-lo) <= 1){
    return;
  }
  merge_sort3(A, lo, m1);
  merge_sort3(A, m1, m2);
  merge_sort3(A, m2, hi);
  merge3(A, lo, m1, m2, hi);
}
