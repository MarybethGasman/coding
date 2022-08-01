#include <bitmap.h>
#include <stdio.h>
#include <string.h>

// given a string
// accept or reject it
// at most three '1' and the number of '1' is odd
int dfa(char *str) {
    // cnt of '1'
    // 1, 2, 3, more
    int cnt = 0;
    // even -> 0, odd -> 1
    int type = 0;
    for (size_t i = 0; i < strlen(str); i++) {
        if (cnt > 3) {
            return 0;
        }
        if (str[i] == '1') {
            type = !type;
            cnt++;
        }
    }
    return type;
}
int main() {
    char *string = "01111";

    int ret = dfa(string);

    if (ret) {
        printf("accept");
    } else {
        printf("reject");
    }
    printf("\n");
    return 0;
}