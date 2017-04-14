#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(int argc, char **argv)
{
    int tid, tgid, sig;
    long ret;
    tgid = atoi(argv[1]);
    tid = atoi(argv[2]);
    sig = atoi(argv[3]);
    ret = syscall(SYS_tgkill, tgid, tid, sig);
    fprintf(stderr, "%ld\n", ret);
    return 0;
}

