#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>



int main()
{

	pid_t ret = fork();
	if(ret == 0)
	{
		wait(NULL);
		printf("Child\n");
	}
	else
	{
		printf("Parent\n");
	}
	return 0;
}
