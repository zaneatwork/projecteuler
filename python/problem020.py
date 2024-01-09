# Find the sum of the digits in the number 100 factorial.

from math import factorial

print(sum((int(char) for char in str(factorial(100)))))
