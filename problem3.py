# What is the largest prime factor of the number 600851475143?
from math import floor, sqrt


def factorize(num, min_factor=3):
    return [f for f in range(min_factor, floor(sqrt(num))) if num % f == 0]


factors = factorize(600851475143)
prime_factors = [f for f in factors if not factorize(f)]

print(max(prime_factors))
