#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(void)
{
  pid_t pid;
  char buffer[100]={"write to std out\n"};
  int var = 100;
  if(write(STDOUT_FILENO,buffer,99) != 99)
  {
	  printf("error");
	  exit(1);
  }
  if((pid = fork()) < 0)
  {
	  printf("fork process error");
	  exit(1);
  }else if(pid == 0)
  {
	  printf("this is child\n");
	  var++;
  }else
  {
	  sleep(10);
  }
  printf("pid=%d, var=%d, ppid=%d\n",getpid(),var,getppid());
  exit(0);
}
