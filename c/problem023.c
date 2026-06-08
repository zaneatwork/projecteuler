/*
 * A perfect number is a number for which the sum of its proper divisors is
 * exactly equal to the number. For example, the sum of the proper divisors of
 * 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *
 * A number n is called deficient if the sum of its proper divisors is less n
 * than and it is called abundant if this sum exceeds n.
 *
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
 * number that can be written as the sum of two abundant numbers is 24. By
 * mathematical analysis, it can be shown that all integers greater than 28123
 * can be written as the sum of two abundant numbers. However, this upper limit
 * cannot be reduced any further by analysis even though it is known that the
 * greatest number that cannot be expressed as the sum of two abundant numbers
 * is less than this limit.
 *
 * Find the sum of all the positive integers which cannot be written as the sum
 * of two abundant numbers.
 */

#include <math.h>
#include <stdio.h>

int main() {
  unsigned long divisorSums[28123] = {1};
  const int maxDivisor = sqrt(28123);

  // Find the sum of divisors for every number from 2 to 28123 at the same
  // time as we find divisors
  for (int i = 2; i < (maxDivisor + 1); i++) {
    divisorSums[i * i] += i;
    for (int j = i + 1; j < (28123 / i); j++) {
      divisorSums[i * j] += i + j;
    }
  }

  // check if the given sum is abundant
  unsigned long sum = 0;
  int abundantNums[28123 + 1] = {0};
  for (int i = 1; i < 28123; i++) {
    if (divisorSums[i] > i) {
      abundantNums[i] = 1;
    }

    int canBeSumOfAbundantNums = 0;
    for (int j = 1; j < i; j++) {
      if (abundantNums[j] > 0 && abundantNums[i - j]) {
        canBeSumOfAbundantNums = 1;
        break;
      }
    }
    if (!canBeSumOfAbundantNums) {
      sum += i;
    }
  }

  printf("%lu\n", sum);

  return 0;
}
