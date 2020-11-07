// there was a weird oddity when allocating 2000MB vs 3000MB. constantly run free -h to see. more memory was allocated when trying to allocate less
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char ** argv)
{
	if(argc!=3)
	{
		printf("usage>%s <memory(MB)> <seconds>\n",argv[0]);
		exit(1);
	}
	int mem = atoi(argv[1]);
	int sec = atoi(argv[2]);
	int * arr = (int*)malloc(sizeof(int)*mem*1024*1024);// allocate argv[1] MB of int memory

	clock_t before = clock();
	int i = 0;
	while(1)
	{
		i = i % (mem*1024*1024);
		arr[i]=i;
		if( (clock() - before)/CLOCKS_PER_SEC >=sec)
		{
			break;
		}
		if (i%100000)
		{
//			printf("%d\n",i);
		}
		i+=1000;
		
	}
	return 0;
}
