extern int lis(int *arr, int length);
#include <stdio.h>
int main() {
    int arr[] = {1, 2, 3, 3, 2, 1};
    int length = sizeof(arr) / sizeof(*arr);

    printf("the longest increasing subsequence is %d\n", lis(arr, length));
    return 0;
}
