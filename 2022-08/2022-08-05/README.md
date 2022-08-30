
### 生成欧拉图
先生成连通图，然后取出所有奇数度顶点，两两处理，如果有边就删去，没有边就以这两个顶点添加一条边。  
但是可能最后得到的图不是连通图，先将就用一下。

TODO: 求欧拉回路

### C11简单实现spinlock自旋锁
```c
void simple_spinlock_lock(atomic_int *lock) {
    int isunlock = 0;
    while(*lock ==0 && atomic_compare_exchange_weak(lock, &isunlock, 1) == 0){
        isunlock = 0;
    }
}
void simple_spinlock_unlock(atomic_int* lock) {
    atomic_store(lock, 0);
}
```
用全局计数器cnt测试，cnt的值等于CPU核心数×10000000
```c
void increment() {
    simple_spinlock_lock(&lock);
    for (int i = 0; i < 10000000; i++) {
        cnt++;
    }
    simple_spinlock_unlock(&lock);
}
```
在Linux环境下运行
```sh
make testspinlock
./testspinlock
the value of cnt is 40000000
```
- 感谢中正的肥肥宅宅羅習五老师😃
- 使用semaphore 若thread没有进入critical section会发生context switch
- 因此若等待时间不长（相对于context switch）使用spinlock会快一点