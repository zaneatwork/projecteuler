/* Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 * which divide evenly into n). If d(a) = b and d(b) = a, where a != b, then a
 * and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * Evaluate the sum of all the amicable numbers under 10,000
 */

#include <stdio.h>

int divisorSum(int n) {
  int sum = 0;
  for (int i = 1; i <= ((n / 2) + 1); i++) {
    sum += n % i == 0 ? i : 0;
  }

  return sum;
}

int main() {
  int amicableSum = 0;

  for (int n = 1; n < 10000; n++) {
    int divSumN = divisorSum(n);
    amicableSum += divSumN != n && divisorSum(divSumN) == n ? n : 0;
  }

  printf("%i\n", amicableSum);
  return 0;
}
