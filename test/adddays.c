/*
 * =====================================================================================
 *
 *       Filename:  adddays.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/06/24 18:41:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "../src/lib/jlib/jdate.h"

int main(int argc, char **argv)
{
	if (argc != 3)
		return 0;

	struct JDate mydate;
	struct JDate newdate;
	jdate_from_str(&mydate, argv[1]);
	jdate_copy(&newdate, &mydate);
	jdate_days_add(&newdate, atoi(argv[2]));

	char *mydate_str = jdate_to_str(&mydate);
	char *newdate_str = jdate_to_str(&newdate);
	printf("%s + %s = %s\n", mydate_str, argv[2], newdate_str);

	free(mydate_str);
	free(newdate_str);

	return 0;
}

