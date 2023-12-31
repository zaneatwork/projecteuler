# The sequence of triangle numbers is generated by adding the natural numbers.
# So the 7th triangle number would be 1+2+3+4+5+6+7=28. 28 is the first
# triangle number to have over five divisors. What is the value of the first
# triangle number to have over five hundred divisors?

from math import floor

## This is too slow!
# def factorize(num, min_factor=1):
#    return [f for f in range(min_factor, num) if num % f == 0]
#
# print([facts for facts in
#      [factorize(sum(range(1, i))) for i in range(1, 13000)]
#      if len(facts) > 500])


# 20k is a lucky guess from trial and error.
triangle_nums = [0] * 20_000

for i in range(1, len(triangle_nums)):
    for j in range(i, len(triangle_nums), i):
        triangle_nums[j] += 1

    if i % 2 == 0:
        num_factors = triangle_nums[i - 1] * triangle_nums[floor(i / 2)]
    else:
        num_factors = triangle_nums[floor((i - 1) / 2)] * triangle_nums[i]

    if num_factors > 500:
        print((i - 1) * floor(i / 2))
        break
