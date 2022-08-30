#include <string.h>
int max(int x, int y) {
    int res = x;
    if (y > res) {
        res = y;
    }
    return res;
}
int lcs(char *str1, int len1, char *str2, int len2) {
    if (len1 == 0 || len2 == 0) {
        return 0;
    }
    if (str1[len1 - 1] == str2[len2 - 1]) {
        return lcs(str1, len1 - 1, str2, len2 - 1) + 1;
    }
    return max(lcs(str1, len1 - 1, str2, len2),
               lcs(str1, len1, str2, len2 - 1));
}
int dplcs(char *str1, int len1, char *str2, int len2) {
    len1 += 1;
    len2 += 1;
    int dp[len1][len2];
    for (int i = 0; i < len1; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < len2; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i < len1; i++) {
        for (int j = 1; j < len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[len1 - 1][len2 - 1];
}
