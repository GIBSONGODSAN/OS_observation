#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char buff[100];
    key = 5678;
    shmid = shmget(key, MAXSIZE, IPC_CREAT|0666);
    shm = shmat(shmid, NULL, 0);
    s = shm;
    printf("Enter some data to write to shared memory\n");
    read(0, buff,100);
    strcpy(shm,buff);
    while(*shm != '*')
        sleep();
    exit(0);
    return 0;
}