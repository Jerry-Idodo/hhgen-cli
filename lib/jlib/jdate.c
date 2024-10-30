/*
 * =====================================================================================
 *
 *       Filename:  jidate.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/06/24 11:20:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "jdate.h"
#include "jlib.h"
#include "jio.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


static const s_uint days_in_months[2][13] =
{  /* error, jan feb mar apr may jun jul aug sep oct nov dec */
	{  0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{  0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } /* leap year */
};

static const uint days_in_year[2][14] =
{  /* 0, jan feb mar apr may  jun  jul  aug  sep  oct  nov  dec */
	{  0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
	{  0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
};

static const uint days_in_4_years[6] =
{
	0, 0, 365, 730, 1095, 1461
};

static const uint years_400 = (365 * 4 + 1) * 100 - 3;
static const uint years_100 = (365 * 4 + 1) * 25 - 1;
static const uint years_4 = (365 * 4 + 1);


uint jdate_valid(const struct JDate *date)
{
	uint val = 0;
	uint year_type = jdate_is_leapyear(date->year);

	if (date->year <= 0)
		return val;
	if (date->month < 1 || date->month > 12)
		return val;
	if (0 < date->day && date->day <= days_in_months[year_type][date->month])
		val = 1;

	return val;
}


/* The Zeller-Congruence Algorithim */
uint jdate_weekday(const struct JDate *date)
{
	int q = (int)date->day;
	int m = (int)date->month;
	int y = (int)date->year;

	// Adjust month for January and February of previous year
	if (m < 3) {
		y--;
		m += 12;
	}

	int k = y % 100;
	int j = y / 100;

	int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
	h = (h + 6) % 7;
	return (uint)h;
}


uint jdate_is_leapyear(const uint year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}


uint jdate_is_leapday(const struct JDate *date)
{
	if (date->month != 2)
		return 0;
	return date->day / 29;
}


uint jdate_is_past_leapday(const struct JDate *date)
{
	if (!jdate_is_leapyear(date->year))
		return 0;
	if (!(date->month > 2))
		return 0;
	return 1;
}


uint jdate_leapyears(const struct JDate *date)
{
	uint num = 0;
	num += date->year / 4;
	num -= date->year / 100;
	num += date->year / 400;
	if (jdate_is_leapyear(date->year)) {
		num -= !(jdate_is_past_leapday(date) || jdate_is_leapday(date)); 
	}

	return num;
}


unsigned long jdate_to_days(const struct JDate *date)
{
	unsigned long days = (date->year - 1) * 365;
	days += jdate_leapyears(date);
	days += (unsigned long)days_in_year[0][date->month];
	days += date->day;

	return days;
}


static inline uint handle_zero_rem(uint *year)
{
	*year = *year - 1;
	uint leap = jdate_is_leapyear(*year);
	return days_in_year[leap][13];
}

void jdate_from_days(struct JDate *date, unsigned long days)
{
	s_uint day = 0;
	s_uint month = 0;
	uint year, rem, leap;

	year = (days / years_400) * 400;
	year += ((days % years_400) / years_100) * 100;
	year += (((days % years_400) % years_100) / years_4) * 4;
	
	rem = ((days % years_400) % years_100) % years_4;

	for (int i = 4; i > 0; i-- ) {
		if (days_in_4_years[i] < rem) {
			year += i;
			rem = rem - days_in_4_years[i];
			break;
		}
	}
	if (rem == 0) {
		rem = handle_zero_rem(&year);	
	}
	leap = jdate_is_leapyear(year);
	for (int i = 12; i > 0; i-- ) {
		if (days_in_year[leap][i] < rem) {
			month = i;
			day = rem - days_in_year[leap][i];
			break;
		}
	}

	date->day = day;
	date->month = month;
	date->year = year;
}


void jdate_days_add(struct JDate *date, const int numdays)
{
	int newdays = (int)jdate_to_days(date) + numdays;
	//printf("old days %lu, new days %d\n", jdate_to_days(date), newdays);
	jdate_from_days(date, newdays);
}


char *jdate_to_str(const struct JDate *date)
{
	static const size_t max = 12;
	if (date->year > 9999) {
		printf("year too large!\n");
		exit(0);			//TODO will do for now
	}

	char *str = (char *)malloc(max * sizeof *str);
	if (str == NULL) {
		printf("Error in jdate_to_str!\n");
		exit(0);
	}
	memset(str, '\0', max);

	snprintf(str, max, "%hu/%hu/%u", date->day, date->month, date->year);
	return str;
}


void jdate_from_str(struct JDate *date, char *str)
{
	static const char *delim = "/";
	date->day = (s_uint)atoi(strtok(str, delim));
	date->month = (s_uint)atoi(strtok(NULL, delim));
	date->year = (uint)atoi(strtok(NULL, delim));
}


void jdate_copy(struct JDate *dest, const struct JDate *source)
{
	dest->day = source->day;
	dest->month = source->month;
	dest->year = source->year;
}

int jdate_input(struct JDate *date, const uint min_year, const uint max_year)
{
	const uint width = 12;
	const char delim[] = "/";
	char datestr[width]; 
	memset(datestr, '\0', width);
	
	printf("Enter Date (dd/mm/yyyy)\n");
	while (1) {
		if (jinput_str("Date: ", datestr,  width) != 1) {
			return -1;
		}
		char *daystr= strtok(datestr, delim);
		char *monthstr = strtok(NULL, delim);
		char *yearstr = strtok(NULL, delim);

		if (!(is_str_int(daystr) || is_str_int(monthstr) || is_str_int(yearstr))) {
			printf("Invalid Input\n");
			continue;
		}
		date->day = (s_uint)atoi(daystr);
		date->month = (s_uint)atoi(monthstr);
		date->year = (uint)atoi(yearstr);
		if (!jdate_valid(date)) {
			printf("Invalid Date\n");
			continue;
		}
		break;
	}

	return 1;
}


