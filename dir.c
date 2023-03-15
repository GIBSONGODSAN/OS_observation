#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
int main(int argc, char *argv[])
{ 
    struct dirent *de;
    DIR *dr = opendir(argv[1]);
    while(de=readdir(dr))
        printf("%s\n",de->d_name);
    closedir(dr);
    return 0;
}