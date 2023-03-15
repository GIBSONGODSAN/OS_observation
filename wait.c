#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{ 
    if(fork()==0)
        printf("Hello from child\n");
    else
    {
        printf("Hello from parent\n");
        wait(NULL);
        printf("Child Terminated\n");
    }
    printf("Bye\n");
    return 0;
}
