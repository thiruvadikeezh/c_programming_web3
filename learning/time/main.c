#include <stdio.h>


#include <time.h>
#include <unistd.h>


int main(){

	time_t result;

	result =  time(NULL);

	printf("%s%ju secs since the Epoch\n", asctime(localtime(&result)), result);

	printf("%s\n", ctime(&result));


	struct tm *t;


	time_t times;

	int secs;

	struct timespec ts = {.tv_sec = 1, .tv_nsec= 0};

	while (1)
	{
		result = time(NULL);

		t = localtime(&result);

		secs = t->tm_sec;

		printf("the second is %d\n", secs);

		nanosleep(&ts, NULL);
	}




	return 0;
}
