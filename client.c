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
    shmid = shmget(key, MAXSIZE, 0666);
    shm = shmat(shmid, NULL, 0);
    for(s=shm; *s!='10'; s++)
        putchar(*s);
    *shm='*';
    exit(0);
    return 0;
}