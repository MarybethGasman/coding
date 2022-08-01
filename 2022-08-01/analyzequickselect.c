#include <stdio.h>
#include <stdlib.h>
extern int findKthLargest(int* nums, int numsSize, int k);
int main() {
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(*arr));

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    findKthLargest(arr, n, 5);

    return 0;

}