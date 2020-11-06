#include<stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>



int main()
{

	pid_t ret = fork();
	if(ret == 0)
	{
		close(STDOUT_FILENO);
		printf("Child\n");
	}
	else
	{
		waitpid(-1,NULL,0);
		printf("Parent\n");
	}
	return 0;
}
