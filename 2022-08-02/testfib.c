extern int fib(int);
extern unsigned long long iter_fib(int);
extern char *big_fib(char *, int);
#define BEGIN 1
#define END 2400   
#define MAX_DIGHT_NUM 21
#include <stdio.h>
#include <time.h>
int main() {
    struct timespec begin;
    struct timespec end;
    

    char fibn[MAX_DIGHT_NUM] = {0};

    for (int i = BEGIN; i < END; i++) {
        clock_gettime(CLOCK_MONOTONIC, &begin);
        big_fib(fibn, i);
        clock_gettime(CLOCK_MONOTONIC, &end);

        printf("%d %llu\n", i, (unsigned long long)end.tv_nsec - begin.tv_nsec);
    }

    return 0;
}
