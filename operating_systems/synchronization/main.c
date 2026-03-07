#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>


void* task(void *arg)
{
	printf("Thread Running\n");
	return NULL;
}

int main()
{
	pthread_t t;
	pthread_create(&t, NULL, task, NULL);

	pthread_join(t, NULL);

	return 0;
}

