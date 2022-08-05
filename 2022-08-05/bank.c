#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <pthread.h>
int main() {
    srand((unsigned)time(NULL));
    int stop;
    int rand_value;
    int numCustomer = 8;
    while (stop == 0) {
        rand_value = rand_r(&rand_value);
        source = rand_value % numCustomer;
        rand_value = rand_r(&rand_value);
        dest = rand_value% numCustomer;

        rand_value = rand_r(&rand_value);
        amount = rand_value%1000;

        bankAccount[source] -=amount;
        bankAccount[dest] +=amount;

        KPI++;
    }
    pthread_t* tid = (pthread_t *)malloc(sizeof(*tid)*numCPU);
    pthread_create(&tid[0], NULL, (void *)moneyTransferP0, (void*)0);

    pthread_create(&tid[1], NULL, (void *)moneyTransferP1, (void*)1);

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    printf("下午三点，银行关门，进行结帐\n");
    printAccountSummary();
    return 0;
}