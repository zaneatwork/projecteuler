# Find the difference between the sum of the squares of the first one hundred 
# natural numbers and the square of the sum.

sum_of_squares = sum([i**2 for i in range(1,101)])
square_of_sums = sum([i for i in range(1,101)])**2
print(square_of_sums - sum_of_squares)
