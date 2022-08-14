extern int knapsack(int *values, int *prices, int length, int volume);
extern int dpknapsack(int *values, int *prices, int length, int volume);
#include <assert.h>
#include <stdio.h>
int main() {
    int values[] = {7, 4, 4};
    int prices[] = {5, 4, 4};
    int length = sizeof(values) / sizeof(*values);
    int volume = 7;
    printf("the max value is %d\n", dpknapsack(values, prices, length, volume));
    assert(dpknapsack(values, prices, length, volume) == knapsack(values, prices, length, volume));
    printf("the max value is %d\n", knapsack(values, prices, length, volume));
    return 0;
}
