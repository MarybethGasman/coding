/**
 * @brief DFA determinsitic finite automation
 *
 * @return int
 */

char stream_add(char a, char b) {
    static int carry = 0;
    char res;
    res = (carry + a + b - 2 * '0') % 10 + '0';
    carry = (carry + a + b - 2 * '0') / 10;
    return res;
}
char stream_div7(char n) {
    static int r = 0;
    int z = (r * 10 + n - '0') / 7;
    r = (r * 10 + n - '0') % 7;
    return z + '0';
}
int dfa_longestbof1(int digit) {
    static int cnt = 0;
    static int size = 0;
    static int mx = 0;
    static int begin = 0;
    if (digit == 1) {
        size++;
        if (size > mx) {
            mx = size;
            begin = cnt - size + 1;
        }
    } else {
        size = 0;
    }
    cnt++;
    return mx;
}
int longestbof1(int *arr, int length, int *begin) {
    int size = 0;
    int mx = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] == 1) {
            size++;
            if (size > mx) {
                mx = size;
                *begin = i - size + 1;
            }
        } else {
            size = 0;
        }
    }
    return mx;
}
#include <limits.h>
int dfa_longestincreasing(int digit) {
    static int cnt = 0;
    static int size = 0;
    static int mx = 0;
    static int begin = 0;
    static int prev = -INT_MAX;
    if (digit > prev) {
        size++;
        if (size > mx) {
            mx = size;
            begin = cnt - size + 1;
        }
    } else {
        size = 1;
    }
    prev = digit;
    cnt++;
    return mx;
}
#define MAX_SIZE 100
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main() {
    // char *num1 = "99";
    // char *num2 = "01";
    // printf("%d\n", 3959 / 7);
    // assert(num1[strlen(num1)] == '\0');
    // for (int i = strlen(num1) - 1; i >= 0; i--) {
    //     printf("%c", stream_add(num1[i], num2[i]));
    // }
    // printf("\n");
    // char *num = "99";
    // for (size_t i = 0; i < strlen(num); i++) {
    //     // assert(stream_div7(num[i]) == (99 / 7) + '0');
    //     printf("%c", stream_div7(num[i]));
    // }
    // printf("\n");
    // int arr[] = {0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0};
    // int length = sizeof(arr) / sizeof(*arr);
    // int begin;

    // int num = longestbof1(arr, length, &begin);

    // for (int i = begin; i < begin + num; i++) {
    //     /* code */
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    srand((unsigned)time(NULL));

    for (int i = 0; i < MAX_SIZE; i++) {
        int randnum = rand()%10;
        // printf("randnum is %d | the size of longest block of 1 is %d\n", randnum, dfa_longestbof1(randnum));
        printf("randnum is %d | the size of longest increasing subsequence is %d\n", randnum, dfa_longestincreasing(randnum));
    }

    return 0;
}