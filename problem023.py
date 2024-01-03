# A perfect number is a number for which the sum of its proper divisors is
# exactly equal to the number. For example, the sum of the proper divisors of
# 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

# A number n is called deficient if the sum of its proper divisors is less n
# than and it is called abundant if this sum exceeds n.

# As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
# number that can be written as the sum of two abundant numbers is 24. By
# mathematical analysis, it can be shown that all integers greater than 28123
# can be written as the sum of two abundant numbers. However, this upper limit
# cannot be reduced any further by analysis even though it is known that the
# greatest number that cannot be expressed as the sum of two abundant numbers
# is less than this limit.

# Find the sum of all the positive integers which cannot be written as the sum
# of two abundant numbers.
from math import sqrt

# Find the sum of divisors for every number from 2 to 28123 at the same
# time as we find divisors
divisor_sums = [1] * 28123
for i in range(2, int(sqrt(28123)) + 1):
    # Include the square of i
    divisor_sums[i * i] += i
    # for all numbers > i but < 28123/i, add the divisor sum for i*j
    for j in range(i + 1, 28123 // i):
        divisor_sums[i * j] += i + j

# check if the given sum is abundant
answers = []
abundant_nums = set()
for n in range(1, 28123):
    if divisor_sums[n] > n:
        abundant_nums.add(n)
    if not any((n - a_num in abundant_nums) for a_num in abundant_nums):
        answers.append(n)

print(sum(answers))
