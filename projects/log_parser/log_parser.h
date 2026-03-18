#ifndef LOG_PARSER_H
#define LOG_PARSER_H



typedef struct
{
	int info_count;
	int error_count;
	int warning_count;
}LogState;

LogState parse_log_file(const char* filename);

int parse_the_file(const char* filename, LogState *out);

#endif
