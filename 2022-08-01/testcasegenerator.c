#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#define MAX_PATH_SIZE 128
#define MAX_BUF_SIZE 4

char filepath[MAX_PATH_SIZE];
char buf[MAX_BUF_SIZE];

int main(int argc, char **argv) {
    srand((unsigned)time(NULL));

    if (argc == 1) {
        errno = EINVAL;
        perror("参数不能为空");
        return 0;
    }

    int n = atoi(argv[1]);
    printf("%d\n",n);
    for (int i = 0; i < n; i++) {
        int number = rand() % 100;
        printf("%d ",number);
    }
    printf("\n");
    return 0;
}
