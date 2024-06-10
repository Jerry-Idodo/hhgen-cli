/*
 * =====================================================================================
 *
 *       Filename:  jidate.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/06/24 11:17:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef JDATE_H
#define JDATE_H

#include "jlib.h"

struct JDate {
	s_uint day;
	s_uint month;
	uint year;
};

uint jdate_valid(const struct JDate *date);
uint jdate_weekday(const struct JDate *date);
uint jdate_is_leapyear(const struct JDate *date);
uint jdate_is_leapday(const struct JDate *date);
uint jdate_is_past_leapday(const struct JDate *date);
uint jdate_leapyears(const struct JDate *date);
unsigned long jdate_to_days(const struct JDate *date);
void jdate_from_days(struct JDate *date, unsigned long days);
int jdate_input(struct JDate *date, const uint min_year, const uint max_year);

#endif
