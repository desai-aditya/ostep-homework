#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int x = 100;

	pid_t ret = fork();
	if(ret==0)
	{
		x++;
		printf("Child:%d\n",x);
	}
	else
	{
		x++;
		x++;
		printf("Parent:%d\n",x);
	}
	return 0;
}
