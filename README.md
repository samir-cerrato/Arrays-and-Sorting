# Arrays-and-Sorting

# Problem 2. Write a function is palindrome that satisfies the following specification:

•Function header. bool is palindrome(char[])

•Pre-condition. s is null-terminated.

•Function body. This should satisfy the following:
is_palindrome(s) =
{
true if s[i] = s[n −1 −i] for all i < (n −1 −i), where n = strlen(s)
false otherwise.

In other words, the function you will implement is an algorithm to check whether the string s is
a palindrome. A palindrome is a string that is the same whether written forwards or backwards.
For instance, racecar is a palindrome. Don’t forget about edge cases: the empty string, and all
length-1 strings, are palindromes.

# Write a function insertion_sort with the following signature:

void insertion_sort(int A[], int n)

Conceptually, insertion sort starts with an empty sorted list of length 0, and then successively inserts values into
their correct place, growing the sorted list length by 1 with each insertion.

# Write a three-way recursive mergesort algorithm

That divides the input array into thirds
recursively sorts each third, and then merges the results. Specifically, write a function merge_sort3
with the following signature:

void merge_sort3(int A[], int lo, int hi)
