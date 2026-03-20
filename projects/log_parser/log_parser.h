#ifndef LOG_PARSER_H
#define LOG_PARSER_H

#define MAX 10

typedef struct
{
	int info_count;
	int error_count;
	int warning_count;
	
	int info_log_lines[MAX];
	int error_log_lines[MAX];
	int warning_log_lines[MAX];

	int info_index;
	int error_index;
	int warning_index;

}LogState;

LogState parse_log_file(const char* filename);

int parse_the_file(const char* filename, LogState *out);

void display_logs(LogState *msg);

#endif
