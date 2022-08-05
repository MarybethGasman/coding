#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int flag = 0; /*0-print thread 1, 1-print thread 2*/
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static pthread_mutex_t mutx = PTHREAD_MUTEX_INITIALIZER;

static void *printThreadId1(void *args) {
    int i = 0, iThreadNo = 0;

    iThreadNo = (int)args;

    while (i < 10) {
        pthread_mutex_lock(&mutx);

        if (flag != 0) {
            pthread_cond_wait(&cond, &mutx);
        }
        if (flag == 0) {
            pthread_cond_signal(&cond);
        }

        printf("Thread No.%d:%d\n", iThreadNo, pthread_self());

        i++;
        flag = 0;

        pthread_mutex_unlock(&mutx);
    }
}

static void *printThreadId2(void *args) {
    int i = 0, iThreadNo = 0;

    iThreadNo = (int)args;

    while (i < 10) {
        pthread_mutex_lock(&mutx);

        if (flag != 1) {
            pthread_cond_wait(&cond, &mutx);
        }
        if (flag == 1) {
            pthread_cond_signal(&cond);
        }

        printf("Thread No.%d:%d\n", iThreadNo, pthread_self());

        i++;
        flag = 0;

        pthread_mutex_unlock(&mutx);
    }
}

int main() {
    pthread_t tid1, tid2;

    if (pthread_create(&tid1, NULL, printThreadId1, (void *)1) != 0) {
        return EXIT_FAILURE;
    }

    if (pthread_create(&tid2, NULL, printThreadId2, (void *)2) != 0) {
        return EXIT_FAILURE;
    }

    if (pthread_join(tid1, NULL) != 0) {
        return EXIT_FAILURE;
    }
    if (pthread_join(tid2, NULL) != 0) {
        return EXIT_FAILURE;
    }

    pthread_mutex_destroy(&mutx);
    pthread_cond_destroy(&cond);

    return EXIT_SUCCESS;
}