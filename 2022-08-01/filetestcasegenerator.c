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
    snprintf(filepath, (long unsigned int)sizeof(filepath), "%s%s", "./input-", argv[1]);

    int fd = open(filepath, O_CREAT | O_APPEND | O_WRONLY | O_NDELAY, 0644);

    if (fd == -1) {
        perror("can not open the file");
    }

    // snprintf(buf, sizeof(buf), "%s", ar)

    int error = write(fd, argv[1], strlen(argv[1]));
    if (error == -1) {
        perror("write failed");
    }

    error = write(fd, "\n", 1);
    if (error == -1) {
        perror("write failed");
    }
    for (int i = 0; i < n; i++) {
        int number = rand() % 100;
        snprintf(buf, sizeof(buf), "%d", number);
        perror(buf);
        write(fd, buf, sizeof(buf));
    }

    error = write(fd, "\n", 1);
    if (error == -1) {
        perror("write failed");
    }
    return 0;
}
