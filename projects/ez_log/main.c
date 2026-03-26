#include <stdio.h>
#include <string.h>

#include "log_parser.h"
#include "ez_logger.h"

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

	display_logs(&state);

	printf("\n\n now the log printng test is being started\n\n");


	LOGI("system init");
	LOGE("LTE not INIT");
	LOGW("lte not working");
	return 0;
}

