#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{

	int pipefd[2];
	pipe(pipefd);
	pid_t ret = fork();
	if(ret == 0)
	{
		close(pipefd[0]);
		dup2(STDOUT_FILENO,pipefd[1]);
		execl("/bin/ls","ls","-l","-a",(char*)NULL);
	}
	else
	{
		printf("Hey there from Parent\n");
		wait(NULL);
		char buf;
		close(pipefd[1]);
		while (read(pipefd[0], &buf, 1) > 0)
                   write(STDOUT_FILENO, &buf, 1);
		close(pipefd[0]);	

	}
	return 0;


}
