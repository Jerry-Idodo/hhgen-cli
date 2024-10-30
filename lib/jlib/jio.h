/*
 * =====================================================================================
 *
 *       Filename:  jio.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/06/24 18:23:53
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef JIO_H
#define JIO_H

#include "jlib.h"
#include <stdio.h>

char jinput_char(const char *prompt, const char min, const char max);
int jinput_int(const char *prompt, const int min, const int max);
double jinput_float(const char *prompt, const double min, const double max);
int jinput_str(const char *prompt, char *str, const uint max_len);
size_t jinput_line(const char *prompt, char *str, const uint max_len);

#endif
