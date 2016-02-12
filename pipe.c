#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int fd[2];
    pid_t pid;
    char line[1024];

    if(pipe(fd) < 0)
    {
        printf("pipe error");
    }else
    {
        printf("before copy pid = %d\n", getpid());
    }
    if((pid = fork()) < 0)
    {
        printf("fork error");
    }else if(pid > 0)
    {
//        printf("pid = %d\n", getpid());
        close(fd[0]);
        write(fd[1],"hello world\n",12);
    }else
    {
  //      printf("pid = %d\n", getpid());
        close(fd[1]);
        n = read(fd[0],line,1024);
        write(STDOUT_FILENO,line,n);
    }
    exit(0);

}
