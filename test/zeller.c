/*
 * =====================================================================================
 *
 *       Filename:  zeller.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/06/24 13:48:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int Zellercongruence(int day, int month, int year) {
    if (month == 1) {
        month = 13;
        year--;
    }
    if (month == 2) {
        month = 14;
        year--;
    }

    int q = day;
    int m = month;
    int k = year % 100;
    int j = year / 100;

    int h = q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
    h = h % 7;

    switch (h) {
        case 0: cout << "Saturday\n"; break;
        case 1: cout << "Sunday\n"; break;
        case 2: cout << "Monday\n"; break;
        case 3: cout << "Tuesday\n"; break;
        case 4: cout << "Wednesday\n"; break;
        case 5: cout << "Thursday\n"; break;
        case 6: cout << "Friday\n"; break;
    }

    return 0;
}


int zeller_congruence(int day, int month, int year) {
    // Adjust month for January and February of previous year
    if (month < 3) {
        year--;
        month += 12;
    }

    // Calculate century (integer division by 100)
    int century = year / 100;

    // Calculate year within century (remainder after division by 100)
    year = year % 100;

    // Zeller's congruence formula
    int weekday = (day + (13 * month - 1) / 5 + year + year / 4 - century / 4 - 2 * century) % 7;

    // Adjust for negative weekday values (0-based indexing)
    int h = (weekday + 7) % 7;

    switch (h) {
        case 0: cout << "Saturday\n"; break;
        case 1: cout << "Sunday\n"; break;
        case 2: cout << "Monday\n"; break;
        case 3: cout << "Tuesday\n"; break;
        case 4: cout << "Wednesday\n"; break;
        case 5: cout << "Thursday\n"; break;
        case 6: cout << "Friday\n"; break;
    }
    return 0;
}


int main() {
    Zellercongruence(8, 6, 2024);  // Example date (dd/mm/yyyy)
    zeller_congruence(8, 6, 2024);  // Example date (dd/mm/yyyy)
    return 0;
}

