# A Pythagorean triplet is a set of three natural numbers, a < b < c, for
# which, a^2 + b^2 = c^2
# For example, 3^2 + 4^2 = 5^2
# There exists exactly one Pythagorean triplet for which a + b + c = 1000
# Find the product abc
from math import sqrt


# method 1 double loop, we only need to check numbers that could add up to 1000
def pyth_triplet():
    for a in range(1, 999):
        for b in range(a, 999):
            c = sqrt(a**2 + b**2)
            if a + b + c == 1000:
                return


pyth_triplet()

print(
    max(
        [
            int(a * b * sqrt(a**2 + b**2))
            for a in range(1, 999)
            for b in range(a, 999)
            if a + b + sqrt(a**2 + b**2) == 1000
        ]
    )
)
