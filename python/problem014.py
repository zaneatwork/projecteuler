# The following iterative sequence is defined for the set of positive integers:
# n -> n/2 (n is even)
# n -> 3n + 1 (n is odd)
# Using the rule above and starting with 13, we generate the following sequence
# 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
# It can be seen that this sequence (starting at 13 and finishing at 1)
# contains 10 terms. Although it has not been proved yet (Collatz Problem), it
# is thought that all starting numbers finish at 1.

# Which starting number, under one million, produces the longest chain?
# NOTE: Once the chain starts the terms are allowed to go above one million.


# This method was too slow. It takes like 60 seconds to compute
# def collatz_sequence(n):
#     return [n] + (
#        collatz_sequence(n // 2 if n % 2 == 0 else 3 * n + 1) if n > 1 else []
#     )
#
#
# sequences = [collatz_sequence(n) for n in range(2, 1_000_000)]
# sized_sequences = [(len(s), s) for s in sequences]
# print(sorted(sized_sequences)[-1][1][0])

# This method avoids duplicating work and is much faster, about 1.5 seconds.
solved = [1]
for n in range(2, 1_000_000):
    current = n
    num_terms = 0
    last_solved = len(solved)
    # If we've already solved for the current number, then just copy its terms
    while current > last_solved:
        current = current // 2 if current % 2 == 0 else 3 * current + 1
        num_terms += 1
    solved += [num_terms + solved[current - 1]]

print(solved.index(max(solved))+1)
