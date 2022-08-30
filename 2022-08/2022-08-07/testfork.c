#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
void saygoodbye() {
    printf("goob bye!\n");
}
// struct softArray {
//     int x;
//     int array[];
// };

int main() {
    // printf("%lu", sizeof(struct softArray));
    // struct softArray ss;
    // ss.x = 10;
    // int sp = 0;
    // printf("%p %p %p\n", &ss.x, ss.array, &sp);
    // unsigned long n = -1;
    int ret = fork();
    if (ret == 0) {
        printf("I'm the child. My pid is %d\n", getpid());
        printf("child exit");
        on_exit(saygoodbye, NULL);

    } else if (ret > 0) {
        printf("I'm the parent. My parent's pid is %d\n", getppid());
        printf("I'm the parent. My pid is %d\n", getpid());
        getchar();
    }

    return 0;
}
