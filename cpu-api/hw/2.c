#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>


int main()
{
	FILE* f = fopen("./tmp.txt","w+");

	pid_t ret =  fork();
	if(ret==0)
	{
		for(int i = 0 ; i  < 100; i++)
			fprintf(f,"%d\n",i);
	}
	else
	{
		for(int i = 0 ; i  < 100; i++)
			fprintf(f,"%d\n",i);
	}
	return 0;
}
