# Let d(n) be defined as the sum of proper divisors of n (numbers less than n
# which divide evenly into n). If d(a) = b and d(b) = a, where a != b, then a
# and b are an amicable pair and each of a and b are called amicable numbers.
#
# Evaluate the sum of all the amicable numbers under 10,000

def divisor_sum(num):
    return sum([d for d in range(1, (num // 2) + 1) if num % d == 0])

## This way is about a second slower because it runs the divisor_sum
## method twice per number
# amicable_sum = 0
#
# for i in range(1, 10_000):
#   div_sum = divisor_sum(i)
#   if div_sum != i and divisor_sum(div_sum) == i:
#       amicable_sum += i
#
# print(amicable_sum)

## This method runs the divisor_sum method once per number then filters by
## amicables.
divisor_sums = [divisor_sum(i) for i in range(0, 10_000)]

amicables = [index
    for index, value in enumerate(divisor_sums)
    if value < 10_000 and value != index and divisor_sums[value] == index]

print(sum(amicables))
