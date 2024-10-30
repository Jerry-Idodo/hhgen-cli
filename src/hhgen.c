/*
 * =====================================================================================
 *
 *       Filename:  hhgen.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/06/24 18:24:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "hhgen.h"
#include "jlib.h"
#include "jio.h"
#include "jdate.h"
#include "stdio.h"
#include <string.h>
#include <stdlib.h>


static const char hh_times[][6] = {
	"00:30", "01:00", "01:30", "02:00", "02:30", "03:00", "03:30", "04:00", "04:30", "05:00", "05:30", "06:00",
	"06:30", "07:00", "07:30", "08:00", "08:30", "09:00", "09:30", "10:00", "10:30", "11:00", "11:30", "12:00",
	"12:30", "13:00", "13:30", "14:00", "14:30", "15:00", "15:30", "16:00", "16:30", "17:00", "17:30", "18:00",
	"18:30", "19:00", "19:30", "20:00", "20:30", "21:00", "21:30", "22:00", "22:30", "23:00", "23:30", "00:00"
};


static int hh_get_time(const char *time)
{
	int val = -1;
	static const int len = 48;
	for (int i = 0; i < len; i++) {
		if (strncmp(hh_times[i], time, 5) == 0) {
			val = i;
			break;
		}
	}

	return val;
}


static void get_daily_hours(const char *prompt, int *day)
{
	char input_str[16];
	static const char *delim = " ";

	while (1) {
		memset(input_str, 0, 16);
		jinput_line(prompt, input_str, 16);
		if (strlen(input_str) != 11 || input_str[2] != ':' || input_str[8] != ':') {
			printf("Invalid Format\n");
			continue;
		}

		const char *open_time = strtok(input_str, delim);
		const char *close_time = strtok(NULL, delim);
		day[0] = hh_get_time(open_time);
		day[1] = hh_get_time(close_time);
		if (day[0] == -1 || day[1] == -1) {
			printf("Wrong time!, chose increaments of 30 mins\n");
			continue;
		}

		break;
	}
}


static void hh_get_opening_times(int opening_times[7][2])
{
	printf("Enter the opening times and closing in the format hh:mm hh:mm ");
	printf("where mm is either 00 or 30\n");
	printf("If the premises is closed, eneter closed.\n");
	get_daily_hours("Monday: ", opening_times[1]);
	get_daily_hours("Tuesay: ", opening_times[2]);
	get_daily_hours("Wednessday: ", opening_times[3]);
	get_daily_hours("Thursday: ", opening_times[4]);
	get_daily_hours("Friday: ", opening_times[5]);
	get_daily_hours("Saturday: ", opening_times[6]);
	get_daily_hours("Sunday: ", opening_times[0]);
}


int hh_data_save(const char *filename, const struct HHDaily *hh_data)
{
	FILE *csvfile = fopen(filename, "w");
	if (csvfile == NULL) {
		printf("Can't open file");
		return -1;
	}
	for (int i = 0; i < 365; i++) {
		char *date = jdate_to_str(&hh_data[i].date);
		fprintf(csvfile, "%s,", date);
		for (int j = 0; j < 47; j++) {
			fprintf(csvfile, "%.4lf,", hh_data[i].usage[j]);
		}
		fprintf(csvfile, "%.4lf\n", hh_data[i].usage[47]);
		free(date);
	}
	fclose(csvfile);
	return 0;
}


int hh_gen_io(void)
{
	struct HHDaily *hh_data = (struct HHDaily *)malloc(365 * sizeof *hh_data);

	struct JDate start_date = {1, 1, 2021};
	double usage = 0.0;
	double baseload = 0.0;
	int opening_times[7][2];
	char filename[32];

	/* Get Start Date*/
	printf("Enter Start Date: ");
	jdate_input(&start_date, 2000, 2030);

	printf("Enter Annual Usage: ");
	usage = jinput_float("Usage: ", -1000000000.0, 1000000000.0);

	printf("Enter baseload in %%: ");
	baseload = jinput_float("Baseload: ", 0, 100);

	printf("Enter csv file name:");
	jinput_str("filename: ", filename, 32);

	hh_get_opening_times(opening_times);

	hh_gen(hh_data, &start_date, usage, baseload, opening_times);

	hh_data_save(filename, hh_data);

	free(hh_data);

	return 0;
}


int hh_gen(struct HHDaily *hh_data,
           const struct JDate *start,
           const double usage,
           const double baseload,
           const int (*opening_times)[2])
{
	uint start_wday = jdate_weekday(start);

	double hh_offpeak;
	double hh_peak;
	hh_offpeak = (48 - opening_times[start_wday][1] + opening_times[start_wday][0]);
	hh_offpeak += 52 * (48 - opening_times[1][1] + opening_times[1][0]);
	hh_offpeak += 52 * (48 - opening_times[2][1] + opening_times[2][0]);
	hh_offpeak += 52 * (48 - opening_times[3][1] + opening_times[3][0]);
	hh_offpeak += 52 * (48 - opening_times[4][1] + opening_times[4][0]);
	hh_offpeak += 52 * (48 - opening_times[5][1] + opening_times[5][0]);
	hh_offpeak += 52 * (48 - opening_times[6][1] + opening_times[6][0]);
	hh_offpeak += 52 * (48 - opening_times[0][1] + opening_times[0][0]);
	hh_peak = 7 * 48 * 52 + 48 - hh_offpeak;

	const double peak_usage = usage / (hh_peak + hh_offpeak * baseload / 100.0);
	const double offpeak_usage = usage / (hh_offpeak + hh_peak * 100.0 / baseload);
	// const double peak_usage = usage / (hh_offpeak * baseload / (100.0 - baseload) + hh_peak);
	// const double offpeak_usage = usage / (hh_offpeak + hh_peak * (100.0 / baseload - 1));

	for (int i = 0; i < 365; i++) {
		int w = (i + start_wday) % 7;
		int j = 0;
		jdate_copy(&hh_data[i].date, start);
		jdate_days_add(&hh_data[i].date, i);

		for (j = 0; j <= opening_times[w][0]; j++) {
			hh_data[i].usage[j] = offpeak_usage;
		}
		for (j = opening_times[w][0] + 1; j <= opening_times[w][1]; j++) {
			hh_data[i].usage[j] = peak_usage;
		}
		for (j = opening_times[w][1] + 1; j < 48; j++) {
			hh_data[i].usage[j] = offpeak_usage;
		}
	}

	return 0;
}
