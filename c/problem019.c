/*
* You are given the following information, but you may prefer to do some
* research for yourself.
* - 1 Jan 1900 was a Monday.
* - Thirty days has September,
* - April, June and November.
* - All the rest have thirty-one,
* - Saving February alone,
* - Which has twenty-eight, rain or shine.
* - And on leap years, twenty-nine.
* - A leap year occurs on any year evenly divisible by 4, but not on a century
* unless it is divisible by 400.
* How many Sundays fell on the first of the month during the twentieth century
* (1 Jan 1901 to 31 Dec 2000)?
*/

#include <stdio.h>

int main()
{
  int daysPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int daysThisMonth;
  int monthsStartingWithMon = 0;
  int dayOfWeek = 0; // dec 31 1901 is a monday

  for (int year = 1901; year <= 2000; year++) {
    for (int month = 0; month < 12; month++) {
      daysThisMonth = daysPerMonth[month];
      
      if (year % 4 == 0 && month == 1 && year % 400 != 0) {
        daysThisMonth = 29;
      }

      dayOfWeek += daysThisMonth % 7;
      dayOfWeek = dayOfWeek % 7;

      if (dayOfWeek == 0) {
        monthsStartingWithMon += 1;
      }
    }
  }

  printf("%i\n", monthsStartingWithMon);
  return 0;
}
