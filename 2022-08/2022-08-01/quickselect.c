#define swap(a, b)                          \
    do {                                    \
        __typeof__ (a) __tmp = (b);         \
        (b) = (a);                          \
        (a) = __tmp;                        \
    } while (0)

int partition(int *arr, int length) {
    int index2a = 0;
    int pivot = arr[index2a];
    for (int i = 0; i < length; i++) {
        if (arr[i] < pivot) {
            swap(arr[i], arr[index2a]);
            index2a++;
            swap(arr[i], arr[index2a]);
        }
    }
    return index2a;
}
// select k-largest element in a given array
int quickselect(int *arr, int length, int k) {

    int index = partition(arr, length);

    if (length - index > k) {
        return index + 1 + quickselect(arr + index + 1, length - index - 1, k);
    }else if (length - index < k) {
        return quickselect(arr, index, k - length + index);
    }
    return index;

}
// leetcode 215
int findKthLargest(int* nums, int numsSize, int k){
    return nums[quickselect(nums, numsSize, k)];
}