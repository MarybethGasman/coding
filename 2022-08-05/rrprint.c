

#include <pthread.h>
#include <stdatomic.h>
#include <stdio.h>
#include <stdlib.h>
int cnt = 0;
atomic_int lock;
extern void simple_spinlock_lock(atomic_int *lock);
extern void simple_spinlock_unlock(atomic_int *lock);

void print() {
    while (cnt < 10) {
        simple_spinlock_lock(&lock);
        cnt++;

        printf("%c%d\n", 'A' + cnt - 1, cnt);

        simple_spinlock_unlock(&lock);
    }
}

int main() {
    int numCPU = 2;

    pthread_t *tid = (pthread_t *)malloc(sizeof(*tid) * numCPU);

    for (long i = 0; i < numCPU; i++)
        pthread_create(&tid[i], NULL, (void *)print, NULL);
    for (long i = 0; i < numCPU; i++)
        pthread_join(tid[i], NULL);

    return 0;
}