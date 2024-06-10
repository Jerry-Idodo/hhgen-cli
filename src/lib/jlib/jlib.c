/*
 * =====================================================================================
 *
 *       Filename:  jilib.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/06/24 19:28:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "jlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>




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


