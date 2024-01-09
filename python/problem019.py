# You are given the following information, but you may prefer to do some
# research for yourself.
# - 1 Jan 1900 was a Monday.
# - Thirty days has September,
# - April, June and November.
# - All the rest have thirty-one,
# - Saving February alone,
# - Which has twenty-eight, rain or shine.
# - And on leap years, twenty-nine.
# - A leap year occurs on any year evenly divisible by 4, but not on a century
# unless it is divisible by 400.
# How many Sundays fell on the first of the month during the twentieth century
# (1 Jan 1901 to 31 Dec 2000)?

days_per_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

months_starting_with_mon = 0

# dec 31 1901 is a monday
day_of_week = 0

for year in range(1901, 2001):
    for month in range(0, 12):
        days_this_month = days_per_month[month]

        # leap year every 4 years, if year % 4 = 0, then feb gets 29
        if year % 4 == 0 and month == 1 and not year % 400 == 0:
            days_this_month = 29

        day_of_week += days_this_month % 7
        day_of_week = day_of_week % 7
        if day_of_week == 0:
            months_starting_with_mon += 1

print(months_starting_with_mon)
