# A palindromic number reads the same both ways.
# The largest palindrome made from the product of two -digit numbers is
# 9009 = 91 * 99
# Find the largest palindrome made from the product of two 3-digit numbers.


def is_palindrome(n):
    return str(n) == str(n)[::-1]


palindromes = [
    x * y
    for x in range(100, 999)
    for y in range(x, 999)
    if is_palindrome(x * y)
]

print(max(palindromes))
