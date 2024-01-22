// Find the sum of all the primes below two million.
#include <math.h>
#include <stdio.h>

// Using the sieve of eratosthenes
long findSumOfPrimesUpTo(int maxValue) {
  long primeSum = 0;
  int isPrime[maxValue];
  for (int i = 0; i < maxValue; i++) {isPrime[i] = 1;}

  for (int i = 2; i <= sqrt(maxValue); i++) {
    if (isPrime[i]) {
      for (int multiple = pow(i, 2); multiple < maxValue; multiple += i) {
        isPrime[multiple] = 0;
      }
    }
  }

  for (int i = 2; i < maxValue; i++) { primeSum += isPrime[i] ? i : 0; }

  return primeSum;
}

int main() {
  printf("%lu\n", findSumOfPrimesUpTo(2000000));
  return 0;
}
