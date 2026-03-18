#include <stdio.h>
#include <string.h>

#include "log_parser.h"

#define file_loc "log.txt"


int main()
{
	LogState state;


	int ret = parse_the_file(file_loc, &state);

	if (ret != 0)
	{
		printf("\nFailed to parse log file\n");
		return 1;
	}




	printf("INFO: %d\n", state.info_count);
	printf("ERROR: %d\n", state.error_count);
	printf("WARNING: %d\n", state.warning_count);

	return 0;
}


