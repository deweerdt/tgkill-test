#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>

pid_t gettid(void)
{
    return syscall(SYS_gettid);
}
static void *f(void *arg)
{
    while(1) {
        fprintf(stderr, "%p pid: %ld, tid: %ld\n", arg, getpid(), gettid());
        sleep(5);
    }
}
int main(void)
{
    pthread_t t[2];
    int i;
    for (i = 0; i < 2; i++) {
        pthread_create(&t[i], NULL, f, (void *)(long)(i + 1));
    }
    pause();
}
