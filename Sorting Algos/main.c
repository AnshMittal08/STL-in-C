#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Comparison function for integers
int compare_int(const void *a, const void *b) {
    int int_a = *(int *)a;
    int int_b = *(int *)b;
    return (int_a > int_b) - (int_a < int_b);
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 10000;  // Size of the array for testing
    srand(time(NULL));

    // Generate random arrays for testing
    int *arr1 = (int *)malloc(sizeof(int) * n);
    int *arr2 = (int *)malloc(sizeof(int) * n);
    int *arr3 = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 1000;
        arr2[i] = arr1[i];  // Duplicate arrays for fair comparison
        arr3[i] = arr1[i];
    }

    // Calculate runtime for Merge Sort
    long long time_merge = calculate_runtime(merge_sort, arr1, n);
    printf("Merge Sort took %lld milliseconds\n", time_merge);

    // Calculate runtime for Quick Sort
    long long time_quick = calculate_runtime(quick_sort, arr2, n);
    printf("Quick Sort took %lld milliseconds\n", time_quick);

    // Test and time Bubble Sort
    int *arr4 = (int *)malloc(sizeof(int) * n);
    memcpy(arr4, arr1, sizeof(int) * n);
    long long time_bubble = calculate_runtime((void (*)(int *, int))bubble_sort, arr4, n);
    printf("Bubble Sort took %lld milliseconds\n", time_bubble);

    // Free memory
    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);

    return 0;
}
