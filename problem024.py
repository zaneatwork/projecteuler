# What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
# 5, 6, 7, 8 and 9?
from itertools import permutations, islice

millionth_perm = next(islice(permutations(range(10)), 999_999, 1_000_000))
print(''.join([str(digit) for digit in millionth_perm]))
