#include <stdio.h>


static void log_write(const char *level, const char *log)
{
	printf("[%s] %s\n", level , log);
}


void LOGI(const char *log)
{
	log_write("INFO", log);
}


void LOGE(const char *log)
{
	log_write("ERROR", log);
}

void LOGW(const char *log)
{
	log_write("WARNING", log);
}


