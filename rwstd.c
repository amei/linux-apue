#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int n;
    char buf[1024];

    while((n = read(STDIN_FILENO,buf,1024)) > 0)
    {
        if(write(STDOUT_FILENO,buf,n) != n)
        {
            printf("wirte error");
        }
    }
    if(n < 0)
    {
        printf("read error");
    }
    exit(0);

}
