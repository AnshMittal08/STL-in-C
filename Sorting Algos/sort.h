#ifndef SORT_H
#define SORT_H

#include <stddef.h>

// Define comparison function type
typedef int (*CompareFunction)(const void *, const void *);

// Sorting algorithms
void merge_sort(int arr[], int n);
void quick_sort(int arr[], int n);
void bubble_sort(void *array, size_t n, size_t size, CompareFunction cmp);
void selection_sort(void *array, size_t n, size_t size, CompareFunction cmp);
void insertion_sort(void *array, size_t n, size_t size, CompareFunction cmp);

// Function to calculate runtime in milliseconds
long long calculate_runtime(void (*sort_func)(int *, int), int arr[], int n);

#endif // SORT_H
