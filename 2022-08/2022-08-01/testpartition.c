#include <assert.h>
extern int partition(int *arr, int length);

int main() {
    int arr[] = {-36, -75, 62, -92, 52, 100, -18, 71, -60, -58, 19, 64, -91, -29, -91, 36, 10, -38, 64, -80};
    int length = sizeof(arr) / sizeof(*arr);
    assert(length == 20);
    int index = partition(arr, length);
    
    for (int i = 0; i < length; i++) {
        if (i < index) {
            assert(arr[i] <= arr[index]);
        }else {
            assert(arr[i] >= arr[index]);
        }
    }

    return 0;
}