# Find the sum of all the primes below two million.

from math import floor, sqrt


def find_primes_eratosthenes(n):
    is_prime = [True] * n
    for potential_prime in range(2, floor(sqrt(n))):
        if is_prime[potential_prime]:
            for multiple in range(potential_prime**2, n, potential_prime):
                is_prime[multiple] = False
    return [index for index, val in enumerate(is_prime) if val and index > 1]


print(sum(find_primes_eratosthenes(2_000_000)))
