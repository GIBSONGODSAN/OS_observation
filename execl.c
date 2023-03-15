#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{ 
    int pid = fork();
    if(pid==0)
        execl(argv[1], argv[2], NULL);
    else
        printf("parent process: %d",pid);

    return 0;
}