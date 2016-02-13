#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
int main(void)
{
    int fd;
    if((fd = creat("file.hole",NULL)) < 0)
    {
        printf("creat error");
        exit(1);
    }
    if(write(fd,buf1,10) != 10)
    {
        printf("write error\n");
        exit(1);
    }
    if(lseek(fd,16384,SEEK_SET) == -1)
    {
        printf("seek error\n");
        exit(1);
    }
    if(write(fd,buf2,10) != 10)
    {
        printf("write buf2 error\n");
        exit(2);
    }
    exit(0);

}
