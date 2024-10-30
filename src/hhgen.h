/*
 * =====================================================================================
 *
 *       Filename:  hhgen.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/06/24 18:17:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef HHGEN_H
#define HHGEN_H

//#include "jdate.h"
#include "../lib/jlib/jdate.h"

struct HHDaily {
	struct JDate date;
	double usage[48];
};

int hh_gen_io(void);
int hh_gen(struct HHDaily *hh_data,
           const struct JDate *start,
           const double usage,
           const double baseload,
           const int (*opening_times)[2]);
int hh_data_save(const char *filename, const struct HHDaily *hh_data);

#endif
