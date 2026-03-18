#include <stdio.h>
#include <string.h>

#include "log_parser.h"


int main()
{ 
	LogState state = parse_log_file("log.txt");

	printf("INFO: %d\n", state.info_count);
	printf("ERROR: %d\n", state.error_count);
	printf("WARNING: %d\n", state.warning_count);

	return 0;
}


