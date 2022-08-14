int knapsack(int *values, int *prices, int length, int volume) {
    if (volume <= 0) {
        return volume;
    }
    if (length == 0) {
        return 0;
    }
    int res;
    int sub1 = knapsack(values, prices, length - 1, volume - prices[length - 1]);
    if (sub1 >= 0) sub1 += values[length - 1];
    int sub2 = knapsack(values, prices, length - 1, volume);

    res = sub1 > sub2 ? sub1 : sub2;
    return res >= 0 ? res : -1;
}
int max(int x, int y) {
    return x > y ? x : y;
}
int dpknapsack(int *values, int *prices, int length, int volume) {
    length+=1;
    volume+=1;
    int dp[length][volume];
    for (int i = 0; i < length; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i < volume; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i < length; i++) {
        for (int j = 1; j < volume; j++) {
            if (j - 1 - prices[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j],
                               dp[i - 1][j - prices[i - 1]] + values[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[length - 1][volume - 1];
}