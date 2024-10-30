/*
 * =====================================================================================
 *
 *       Filename:  jiio.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/06/24 10:44:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "jio.h"
#include "jlib.h"
#include "stdio.h"
#include <stdlib.h>
#include <string.h>

#ifndef __FUNCTION_NAME__
#ifdef WIN32   //WINDOWS
#define __FUNCTION_NAME__   __FUNCTION__  
#else          //*NIX
#define __FUNCTION_NAME__   __func__ 
#endif
#endif

static void err_invalid(void)
{
	printf("\nInvalid Input\n");
}


static void err_range(void)
{
	printf("\nOut of range! Enter values between: ");
}


static void error_message(const char *func, const char *message)
{
	printf("Error in function: %s. %s", func, message);
}

static inline void flush_input(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}


static void get_input(char *buff, const uint width)
{
	int newline = 0;
	memset(buff, 0, width);

	fgets(buff, width, stdin);

	if (strcspn(buff, "\n") != strlen(buff)) newline = 1;
	buff[strcspn(buff, "\n")] = 0;
	if (!newline) flush_input();
}


char jinput_char(const char *prompt, const char min, const char max)
{
	char val;
	const uint width = 4;
	char buff[width];
	
	while (1) {
		printf("%s", prompt);
		get_input(buff, width);

		if (strlen(buff) != 1) {
			err_invalid();
			continue;
		}
		if (sscanf(buff, "%c", &val) != 1) {
			err_invalid();
			continue;
		}
		if (val < min || val > max) {
			err_range();
			printf("%c - %c\n", min, max);
			continue;
		}
		break;
	}

	return val;
}


int jinput_int(const char *prompt, const int min, const int max)
{
	int val;
	const uint width = 16;
	char buff[width];

	while (1) {
		printf("%s", prompt);
		get_input(buff, width);

		if (!is_str_int(buff)) {
			err_invalid();
			continue;
		}
		if (sscanf(buff, "%d", &val) != 1) {
			err_invalid();
			continue;
		}
		if (val < min || val > max) {
			err_range();
			printf("%d - %d\n", min, max);
			continue;
		}
		break;
	}

	return val;
}


double jinput_float(const char *prompt, const double min, const double max)
{
	double val;
	const uint width = 32;
	char buff[width];

	while (1) {
		printf("%s", prompt);
		get_input(buff, width);

		if (!is_str_float(buff)) {
			err_invalid();
			continue;
		}
		if (sscanf(buff, "%lf", &val) != 1) {
			err_invalid();
			continue;
		}
		if (val < min || val > max) {
			err_range();
			printf("%lf - %lf", min, max);
			continue;
		}
		break;	
	}

	return val;
}


int jinput_str(const char *prompt, char *str, const uint max_len)
{
	const uint width = max_len + 1;

	char *buff = (char *)malloc(width * sizeof(*buff));
	if (buff == NULL) {
		error_message(__FUNCTION_NAME__, "Unable to Allocate Memory");
		return -1;
	}
	memset(buff, '\0', width);

	while (1) {
		printf("%s", prompt);
		get_input(buff, width);

		if (strlen(buff) == 0)
			continue;
		if (sscanf(buff, "%s", str) != 1) {
			err_invalid();
		}
		break;
	}

	free(buff);
	return 1;
}


size_t jinput_line(const char *prompt, char *str, const uint max_len)
{
	char *buff = NULL;
	size_t len = 0;
	size_t nread = 0;

	printf("%s", prompt);
	nread = getline(&buff, &len, stdin);
	if (buff[strlen(buff) - 1] == '\n')
		buff[strlen(buff) - 1] = '\0';

	strncpy(str, buff, max_len);

	free(buff);
	return nread;
}

