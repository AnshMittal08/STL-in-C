#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

// Helper function for swapping elements
void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

// Function to calculate runtime in milliseconds
long long calculate_runtime(void (*sort_func)(int*, int), int arr[], int n) {
    struct timeval before, after;
    gettimeofday(&before, NULL);
    long long before_millis = before.tv_sec * 1000LL + before.tv_usec / 1000;

    sort_func(arr, n);

    gettimeofday(&after, NULL);
    long long after_millis = after.tv_sec * 1000LL + after.tv_usec / 1000;

    return after_millis - before_millis;
}

// Merge Sort Implementation
void merge(int arr[], int aux[], int left, int mid, int right) {
    for (int k = left; k <= right; k++) aux[k] = arr[k];

    int i = left;
    int j = mid + 1;
    for (int k = left; k <= right; k++) {
        if (i > mid) arr[k] = aux[j++];
        else if (j > right) arr[k] = aux[i++];
        else if (aux[i] <= aux[j]) arr[k] = aux[i++];
        else arr[k] = aux[j++];
    }
}

void merge_sort_recursive(int arr[], int aux[], int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort_recursive(arr, aux, left, mid);
    merge_sort_recursive(arr, aux, mid + 1, right);
    merge(arr, aux, left, mid, right);
}

void merge_sort(int arr[], int n) {
    int *aux = (int *)malloc(n * sizeof(int));
    merge_sort_recursive(arr, aux, 0, n - 1);
    free(aux);
}

// Quick Sort Implementation
void quick_sort_recursive(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[left];
    int i = left + 1;

    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i++], &arr[j], sizeof(int));
        }
    }

    swap(&arr[left], &arr[i - 1], sizeof(int));  // Correct pivot placement
    quick_sort_recursive(arr, left, i - 2);
    quick_sort_recursive(arr, i, right);
}

void quick_sort(int arr[], int n) {
    quick_sort_recursive(arr, 0, n - 1);
}

// Bubble Sort Implementation
void bubble_sort(void *array, size_t n, size_t size, CompareFunction cmp) {
    char *arr = (char *)array;  // Cast to char* for pointer arithmetic
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - 1 - i; j++) {
            void *a = arr + j * size;
            void *b = arr + (j + 1) * size;
            if (cmp(a, b) > 0) {  // Swap if a > b
                swap(a, b, size);
            }
        }
    }
}

// Selection Sort Implementation
void selection_sort(void *array, size_t n, size_t size, CompareFunction cmp) {
    char *arr = (char *)array;
    for (size_t i = 0; i < n - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < n; j++) {
            if (cmp(arr + j * size, arr + min_index * size) < 0) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(arr + i * size, arr + min_index * size, size);
        }
    }
}

// Insertion Sort Implementation
void insertion_sort(void *array, size_t n, size_t size, CompareFunction cmp) {
    char *arr = (char *)array;
    for (size_t i = 1; i < n; i++) {
        char temp[size];
        memcpy(temp, arr + i * size, size);
        size_t j = i;
        while (j > 0 && cmp(temp, arr + (j - 1) * size) < 0) {
            memcpy(arr + j * size, arr + (j - 1) * size, size);
            j--;
        }
        memcpy(arr + j * size, temp, size);
    }
}
