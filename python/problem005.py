# What is the smallest positive number that is evenly divisible by all of the
# numbers from 1 to 20
from functools import reduce
from math import floor

def greatest_common_divisor(x, y):
    return greatest_common_divisor(y, floor(x % y)) if y > 0 else x

def least_common_multiple(x, y):
    return floor(x / greatest_common_divisor(x, y) * y)

print(reduce(least_common_multiple, range(1, 20)))
