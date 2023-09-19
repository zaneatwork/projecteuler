# By considering the terms in the Fibonacci sequence whose values
# do not exceed four million, find the sum of the even-valued terms.

fibo = [1, 2]
while fibo[-1] < 4_000_000:
    fibo.append(fibo[-1] + fibo[-2])

print(sum(filter(lambda x: x % 2 == 0, fibo)))
