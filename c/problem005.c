// What is the smallest positive number that is evenly divisible by all of the
// numbers from 1 to 20

#include <stdio.h>

// We need to find the least common multiple (lcm) of 1 through 20
// To do this, we need to multiple all the prime factors of 1-20 together
// A better explanation of this can be found here:
// https://en.wikipedia.org/wiki/Least_common_multiple#Using_prime_factorization
int lcmUntil(int n) {
  int primeFactorsProduct = 1;
  for (int i = 2; i <= n; i++) {
    // if i is prime (i.e. not divisble by a multiple of the previous elements)
    if (primeFactorsProduct % i) {
      // find the largest multiple of the prime i that is less than n
      int x = i;
      while (x * i <= n) {
        x *= i;
      }
      // finally multiply our product by it
      primeFactorsProduct *= x;
    }
  }
  return primeFactorsProduct;
}

int main() {
  printf("%i\n", lcmUntil(20));
  return 0;
}
