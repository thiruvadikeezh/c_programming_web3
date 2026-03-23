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
	

	int line_number = 0;
	
	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		
		if(strstr(line, "[INFO]"))
		{
			out->info_log_lines[out->info_count] = line_number;
			out->info_count++;
			out->info_index++;
		}
		else if (strstr(line, "[WARNING]"))
		{
		
			out->warning_log_lines[out->warning_index] = line_number;
			out->warning_count++;
			out->warning_index++;
		}
		else if (strstr(line, "[ERROR]"))
		{

			out->error_log_lines[out->error_index] = line_number;
			out->error_count++;
			out->error_index++;
		}

	}


	fclose(file);
	return 0; //success;

}


void display_logs(LogState *msg)
{
	int i;
	
	printf("\nINFO:\n");
	for(int i = 0 ; i<msg->info_count; i++)
	{
		printf("Line: %d\n", msg->info_log_lines[i]);
	}
	
	printf("\nERROR:\n");

	for(int i = 0 ; i<msg->error_count; i++)
	{
		printf("Line: %d\n", msg->error_log_lines[i]);

	}
	
	printf("\nWarning:\n");
	
	for(int i = 0; i<msg->warning_count; i++)
	{
		printf("Line: %d\n", msg->warning_log_lines[i]);
	}


}

