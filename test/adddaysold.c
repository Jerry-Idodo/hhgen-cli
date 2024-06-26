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
	if (argc != 2)
		return 0;

	struct JDate mydate;
	jdate_from_str(&mydate, argv[1]);
	
	jdate_days_add(&mydate, 1);
	char *newdate = jdate_to_str(&mydate);

	printf("%s\n", newdate);
	free(newdate);

	struct JDate start_date;
	jdate_input(&start_date, 2000, 2030);
	char *startdate = jdate_to_str(&mydate);
	printf("%s\n", startdate);
	free(startdate);

	return 0;
}

