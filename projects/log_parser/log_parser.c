#include <stdio.h>
#include <string.h>


#include "log_parser.h"

LogState parse_log_file(const char* filename)
{
	FILE *file;
	char line[256];

	LogState log = {0};

	file = fopen(filename, "r");

	if (file == NULL){

		printf("Error Opening The File name\n");
		perror("\nThis is an error printing message from perror\n");

		return log;

	}

	while(fgets(line, sizeof(line), file)) {

		if (strstr(line, "[INFO]")){
			log.info_count++;
		} else if (strstr(line, "[ERROR]")){
			log.error_count++;
		} else if (strstr(line, "[WARNING]")){
			log.warning_count++;
		}
	}
	fclose(file);
	

	return log;
}


int parse_the_file(const char* filename, LogState *out)
{

	FILE *file = fopen(filename, "r");

	char line[256];

	if( file == NULL)
	{

		perror("File Not Found");

		return -1;
	}

	*out = (LogState){0}; //initialize
	
	while (fgets(line, sizeof(line), file))
	{
		if(strstr(line, "[INFO]"))
			out->info_count++;
		else if (strstr(line, "[WARNING]"))
			out->warning_count++;
		else if (strstr(line, "[ERROR]"))
			out->error_count++;
	}

	fclose(file);
	return 0; //success;

}


void display_logs(LogState *msg)
{
	printf("info:\n");
	printf("error:\n");
	printf("warning:\n");
}

