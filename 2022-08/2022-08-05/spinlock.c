#include <stdatomic.h>

void simple_spinlock_lock(atomic_int *lock) {
    int isunlock = 0;
    while(*lock ==0 && atomic_compare_exchange_weak(lock, &isunlock, 1) == 0){
        isunlock = 0;
    }
}
void simple_spinlock_unlock(atomic_int* lock) {
    atomic_store(lock, 0);
}