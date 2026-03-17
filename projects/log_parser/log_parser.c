#include <stdio.h>
#include <string.h>


#include "log_parser.h"

typedef struct 
{
	int info_count;
	int warning_count;
	int error_count;
}logs;


void parse_log_file(const char* filename)
{
	FILE *file;
	char line[256];

	logs log = {0};

	file = fopen(filename, "r");

	if (file == NULL){

		printf("Error Opening The File name\n");
		perror("\nThis is an error printing message from perror\n");

		return;

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

	printf("INFO: %d\n", log.info_count);
	printf("ERROR: %d\n", log.error_count);
	printf("WARNING: %d\n", log.warning_count);
}

