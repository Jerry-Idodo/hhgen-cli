#include "../lib/jilib/jilib.h"
#include "../lib/jilib/jidate.h"
#include <stdio.h>

int main (void)
{
	char *weekday;
	struct JDate mydate = {1,1,1};
		
	jdate_input(&mydate, 1000, 9999);
	uint choice = jdate_weekday(&mydate);

	switch (choice) {
	case 0:
		weekday = "Sunday";
		break;
	case 1:
		weekday = "Monday";
		break;
	case 2:
		weekday = "Tuesday";
		break;
	case 3:
		weekday = "Wednesday";
		break;
	case 4:
		weekday = "Thursday";
		break;
	case 5:
		weekday = "Friday";
		break;
	case 6:
		weekday = "Saturday";
		break;
	default:
		weekday = "Error";
		break;
	}

	printf("%d/%d/%d is a %s\n", mydate.day, mydate.month, mydate.year, weekday);
	
	return 0;
}
