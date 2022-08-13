extern int change(int *money, int length, int amount);
#include <stdio.h>
int main() {
    int money[] = {5, 2, 1};
    int length = sizeof(money) / sizeof(*money);
    int amount = 100;

    printf("the minium num of coins is %d\n",change(money, length, amount));
    return 0;
}
