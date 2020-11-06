//variants for exec family calls

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main()
{
	pid_t ret = fork();
	if(ret == 0)
	{
		execl("/bin/ls","ls","-l","-a",(char*)NULL);
		//execlp("/bin/ls","ls","-l","-a",(char*)NULL);
		//execle("/bin/ls","ls","-l","-a",(char*)NULL);
		char* arr[] = {"ls","-l","-a",  NULL};
		//execv("/bin/ls",arr);
		//execvp("/bin/ls",arr);
		//execvpe("/bin/ls",arr,NULL);
		printf("This will not be printed\n");
	}
	else
	{
		wait(NULL);
		printf("Parent\n");
	}

	return 0;
}
