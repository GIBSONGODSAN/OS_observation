#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define MAXSIZE 27

int main()
{ 
    char c;
    int shmid;
    key_t key;
    char *shm, *s;
    key = 5678;
    shmid = shmget(key, MAXSIZE, IPC_CREAT|0666);
    shm = shmat(shmid, NULL, 0);
    s = shm;
    for(c='a'; c<='z'; c++)
        *s++ = c;
    while(*shm != '*')
        sleep();
    exit(0);
    return 0;
}