#include <assert.h>
#include <limits.h>
int change(int *money, int length, int amount) {
    int minium = INT_MAX;
    if (amount <= 0) {
        return amount;
    }
    for (int i = 0; i < length; i++) {
        for (int j = 1; j * money[i] <= amount; j++) {
            int num = change(money, length, amount - j * money[i]);
            if (num >= 0) {
                if (num + j < minium) minium = num + j;
            }
        }
    }
    return minium == INT_MAX ? -1 : minium;
}
int lis(int *arr, int length) {
    int dp[length];

    int res = 0;
    for (int i = 0; i < length; i++) {
        int maxmium = 0;
        // assert(dp[i] == 0);
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[j] > maxmium) maxmium = dp[j];
        }
        dp[i] = maxmium + 1;
        if (dp[i] > res) res = dp[i];
    }

    return res;
}