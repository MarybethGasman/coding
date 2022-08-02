#include <stdio.h>
#include <stdlib.h>
#define MAX_DIGHT_NUM 21
extern void big_add(char *dest, char *num1, char *num2);

int main() {
    char fibi[MAX_DIGHT_NUM];
    char fibi_1[MAX_DIGHT_NUM];
    char fibi_2[MAX_DIGHT_NUM];

    for (size_t i = 0; i < MAX_DIGHT_NUM; i++) {
        fibi_1[i] = '0';
        fibi_2[i] = '0';
    }
    fibi_1[MAX_DIGHT_NUM - 2] = '1';


    big_add(fibi, fibi_1, fibi_2);

    printf("the result is %s\n",fibi);
    return 0;
}