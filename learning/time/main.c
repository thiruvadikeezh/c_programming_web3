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
	while (1)
	{
		times = time(NULL);

		t = localtime(&times);

		secs = t->tm_sec;

		printf("the second is %d\n", secs);
		sleep(1);
	}


	return 0;
}
