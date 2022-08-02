#include <stdlib.h>
#include <string.h>

#include <bigfib.h>

int fib(int n) {
    if (n < 2) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}


unsigned long long iter_fib(int n) {
    unsigned long long fibi_2 = -1, fibi_1 = 1;
    unsigned long long fibi = 0;
    for (int i = 0; i < n; i++) {
        fibi_2 = fibi_1;
        fibi_1 = fibi;
        fibi = fibi_1 + fibi_2;
    }
    return fibi;
}



void big_add(char *dest, char *num1, char *num2) {
    int carry = 0;
    int i = MAX_DIGHT_NUM - 2;
    for (; i >= 0; i--) {
        dest[i] = ((carry + num1[i] + num2[i] - 2 * '0') % 10) + '0';
        carry = (carry + num1[i] + num2[i] - 2 * '0') / 10;
    }
    // dest[i] = carry + '0';
}

char *big_fib(char *fibi, int n) {
    char fibi_1[MAX_DIGHT_NUM] = {0};
    char fibi_2[MAX_DIGHT_NUM] = {0};

    for (size_t i = 0; i < MAX_DIGHT_NUM - 1; i++) {
        fibi_1[i] = '0';
        fibi_2[i] = '1';
        fibi[i] = '0';
    }

    fibi_1[MAX_DIGHT_NUM - 2] = '1';

    for (int i = 0; i < n; i++) {
        strcpy(fibi_2, fibi_1);
        strcpy(fibi_1, fibi);
        big_add(fibi, fibi_1, fibi_2);
    }
    return fibi;
}