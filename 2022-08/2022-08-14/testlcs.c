extern int lcs(char *str1, int len1, char *str2, int len2);
extern int dplcs(char *str1, int len1, char *str2, int len2);
#include <assert.h>
#include <stdio.h>
#include <string.h>
int main() {
    char str1[] = "asbctchda";
    char str2[] = "rtwabgjcktfd";
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    printf("the longest common subsequence is %d\n", dplcs(str1, len1, str2, len2));
    assert(dplcs(str1, len1, str2, len2) == lcs(str1, len1, str2, len2));
    printf("the longest common subsequence is %d\n", lcs(str1, len1, str2, len2));
    return 0;
}
