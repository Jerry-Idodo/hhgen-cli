/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  main function 
 *
 *        Version:  1.0
 *        Created:  07/06/24 18:06:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jerry (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "hhgen.h"

int main(int argc, char **argv)
{
	if (argc != 1) {
		// TODO: Default Times
		return 0;
	}

	int status = hh_gen_io();
	
	return status;
}

