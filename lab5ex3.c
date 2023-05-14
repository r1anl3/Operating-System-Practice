#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
int x = 0;
void* processA()
{
	while (1)
	{
		x = x + 1;
		if (x == 20)
		{
			x = 0;
		}
		printf("PA: x = %d\n", x);
		sleep(1);
	}
}
void* processB()
{
	while (1)
	{
		x = x + 1;
		if (x == 20)
		{
			x = 0;
		}
		printf("PB: x = %d\n", x);
		sleep(1);
	}
}

void main()
{
	pthread_t th1, th2;
	pthread_create(&th1, NULL, &processA, NULL);
	pthread_create(&th2, NULL, &processB, NULL);;
	while (1);
}
