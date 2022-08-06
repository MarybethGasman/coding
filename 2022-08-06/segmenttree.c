#include <stdio.h>

// limit for array size
#define N 100000
// Max size of tree
int tree[2 * N];

// function to build the tree
void build(int arr[], int length) {
    // insert leaf nodes in tree
    for (int i = 0; i < length; i++)
        tree[length + i] = arr[i];

    // build the tree by calculating parents
    for (int i = length - 1; i > 0; --i)
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
}

// function to update a tree node
void updateTreeNode(int p, int value, int length) {
    // set value at position p
    tree[p + length] = value;
    p = p + length;

    // move upward and update parents
    for (int i = p; i > 1; i >>= 1)
        tree[i >> 1] = tree[i] + tree[i ^ 1];
}

// function to get sum on interval [l, r)
int query(int l, int r, int length) {
    int res = 0;

    // loop to find the sum in the range
    for (l += length, r += length; l < r; l >>= 1, r >>= 1) {
        if (l & 1)
            res += tree[l++];

        if (r & 1)
            res += tree[--r];
    }

    return res;
}

// driver program to test the above function
int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // n is global
    int n = sizeof(a) / sizeof(*a);

    // build tree
    build(a, n);

    // print the sum in range(1,2) index-based
    printf("%d\n", query(1, 3, n));

    // modify element at 2nd index
    updateTreeNode(2, -1, n);

    // print the sum in range(1,2) index-based
    printf("%d\n", query(1, 3, n));

    return 0;
}
