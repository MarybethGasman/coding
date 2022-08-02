extern int fib(int);
extern unsigned long long iter_fib(int);
extern char *big_fib(char *, int);
#define BEGIN 1
#define END 101
#define MAX_DIGHT_NUM 21
#include <stdio.h>
int main() {
    char fibn[MAX_DIGHT_NUM] = {0};

    for (int i = BEGIN; i < END; i++) {
        printf("the fib of %d is %s\n", i, big_fib(fibn, i));
    }

    return 0;
}
