#include <pthread.h>
#include <stdatomic.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int cnt = 0;
atomic_int lock;
extern void simple_spinlock_lock(atomic_int *lock);
extern void simple_spinlock_unlock(atomic_int *lock);
void increment() {
    simple_spinlock_lock(&lock);
    for (int i = 0; i < 10000000; i++) {
        cnt++;
    }

    simple_spinlock_unlock(&lock);
}
int main(int argc, char **argv) {
    int numCPU = sysconf(_SC_NPROCESSORS_ONLN);

    pthread_t *tid = (pthread_t *)malloc(sizeof(*tid) * numCPU);

    for (long i = 0; i < numCPU; i++)
        pthread_create(&tid[i], NULL, (void *)increment, (void *)i);
    for (long i = 0; i < numCPU; i++)
        pthread_join(tid[i], NULL);

    printf("the value of cnt is %d\n", cnt);
    return 0;
}