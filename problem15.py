# Starting in the top left corner of a 2x2 grid, and only being able to move to
# the right and down, there are exactly routes to the bottom right corner.

# How many such routes are there through a 20 x 20 grid?

from math import factorial

# The formula for the number of contigous routes for a (n*n) square grid is 
# (2n)! / (n! * n!) 
# This is also the center of the 2*nth row of pascal's triangle. 
# So for 2x2 grid, it would be the middle of the 4th row (6) and so on.

print(factorial(2*20) / (factorial(20) * factorial(20)))
