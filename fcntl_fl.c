#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int var;
    int fd;
    if(argc != 2)
    {
        exit(1);
    }
    fd = open(argv[1],O_WRONLY);

    if((var = fcntl(fd,F_GETFL,0)) < 0)
    {
        exit(1);
    }
    switch(var & O_ACCMODE)
    {
        case O_RDONLY:
            printf("read only");
        break;
        case O_WRONLY:
            printf("write only");
        break;
        case O_RDWR:
            printf("read write");
        break;
        default:break;

    }
    if(var & O_APPEND)
    {
        printf("append mode");
    }
    exit(0);
}
