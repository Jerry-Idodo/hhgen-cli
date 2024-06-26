#include "../lib/jilib/jilib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


static void err_invalid(void)
{
	printf("\nInvalid Input\n");
}


static void err_range(void)
{
	printf("\nOut of range! Enter values between: ");
}


static inline void flush_input(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}


static void get_input(char *buff, uint width)
{
	int newline = 0;
	memset(buff, 0, width);

	fgets(buff, width, stdin);

	if (strcspn(buff, "\n") != strlen(buff)) newline = 1;
	buff[strcspn(buff, "\n")] = 0;
	if (!newline) flush_input();
}


int is_str_int(char *str)
{
	for (int i = 0; i < strlen(str); i++) {
		if (i == 0 && str[i] == '-')
			continue;
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}


int is_str_float(char *str)
{
	int count = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '.')
			count += 1;
		if (i == 0 && str[i] == '-')
			continue;
		if (!isdigit(str[i]) && str[i] != '.')
			return 0;
	}

	if (count > 1)
		return 0;
	else
		return 1;
}


char ji_input_c(char *prompt, char min, char max)
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


int ji_input_i(char *prompt, int min, int max)
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


double ji_input_f(char *prompt, double min, double max)
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


/* Testing above functions */
int main (void)
{
	char c = ji_input_c("Enter lowercase character: ", 'a', 'z');
	printf("You entered %c\n", c);

	int i = ji_input_i("Enter an integer: ", 0, 1000);
	printf("You entered %d\n", i);

	double f = ji_input_f("Enter a number: ", -1000.0, 1000.0);
	printf("You entered %f\n", f);

	return 0;
}
