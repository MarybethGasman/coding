#include <dbg.h>

extern int findKthLargest(int* nums, int numsSize, int k);

int main() {
    int arr[] = {3,2,1,5,6,4};
    int length = sizeof(arr) / sizeof(*arr);
    int k = 2;

    debug("the answer is %d\n", findKthLargest(arr, length, k));

    return 0;
}

