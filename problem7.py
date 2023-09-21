# What is the 10,001st prime number?
from math import floor, sqrt


def find_primes_eratosthenes(n):
    is_prime = [True] * n
    for potential_prime in range(2, floor(sqrt(n))):
        if is_prime[potential_prime]:
            for multiple in range(potential_prime**2, n, potential_prime):
                is_prime[multiple] = False
    return [index for index, val in enumerate(is_prime) if val and index > 1]


# find the primes of the first 200,000 integers and hope that the 10,001st is
# in there. The list is indexed at 0, so we want index 10,000
print(find_primes_eratosthenes(200_000)[10_000])
