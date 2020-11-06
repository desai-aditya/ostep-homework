#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int pipefd[2];
	pipe(pipefd);
	pid_t ret = fork();
	if(ret==0)
	{
		//child
		close(pipefd[0]);
		FILE * fp = fdopen(pipefd[1],"w+");// convert file descriptor to FILE *
		write(STDOUT_FILENO,"hello\n",strlen("hello\n"));
		fprintf(fp,"a");
		close(pipefd[1]);
	}
	else
	{
		//parent
		close(pipefd[1]);
		char buf;
		while(read(pipefd[0],&buf,1)>0);
		printf("goodbye\n");	
		close(pipefd[0]);
	}
	return 0;
}
