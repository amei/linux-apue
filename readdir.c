#include "stdio.h"
#include "stdlib.h"
#include <dirent.h>
int main(int argc,char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if(argc != 2)
    {
        printf("error parament");
        exit(1);
    }
    if((dp = opendir(argv[1])) == NULL)
    {
        printf("opendir error");
        exit(1);
    }
    while((dirp = readdir(dp)) != NULL)
    {
        printf("\n dir name : %s",dirp->d_name);
    }
    closedir(dp);
    exit(0);
}
