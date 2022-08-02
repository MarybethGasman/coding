#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE 10000
extern int findKthLargest(int *nums, int numsSize, int k);

int *alloc_array(int n) {
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    return arr;
}

int main() {
    srand((unsigned int)time(NULL));

    struct timespec begin;
    struct timespec end;
    for (int i = 1; i < MAX_ARRAY_SIZE; i++) {
        int *arr = alloc_array(i);

        clock_gettime(CLOCK_MONOTONIC, &begin);
        findKthLargest(arr, i, rand() % i);
        clock_gettime(CLOCK_MONOTONIC, &end);

        printf("%d %llu\n", i, (unsigned long long)end.tv_sec - begin.tv_sec);
        free(arr);
    }

    return 0;
}