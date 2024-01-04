# What is the index of the first term in the Fibonacci sequence to contain
# 1000 digits?

thousand_digit_num = 10**999

fibo = [1, 2]
while fibo[-1] < thousand_digit_num:
    fibo.append(fibo[-1] + fibo[-2])

print(len(fibo)+1)
