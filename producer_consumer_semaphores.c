#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int mutex=1, full=0, empty=3, x=0;

void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("Producer produces the item %d\n",x);
    mutex=signal(mutex);
}

void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    x--;
    printf("Consumer consumes the item %d\n"x);
    mutex=signal(mutex);
}
int wait(int s)
{
    return(--s);
}
int signal(int s)
{
    return(++s);
}

int main()
{ 
    int n;
    printf("1.Producer\t2.Consumer\t3.Exit\n");
    while(1)
    {
        case 1:
            if((mutex==1)&&(empty!=0))
            {
                producer();
                break;
            }
            else
            {
                printf("Buffer is Full");
                break;
            }
        case 2:
            if((full!=0)&&(mutex==1))
            {
                consumer();
                break;
            }
            else
            {
                printf("Buffer is Empty");
                break;
            }
        default:
            printf("EXITING");
            break;
    }
    return 0;
}