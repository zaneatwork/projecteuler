// What is the 10,001st prime number?

#include <math.h>
#include <stdio.h>

// Using the sieve of eratosthenes
int findNthPrimeUpTo(int n, int maxValue) {
  int isPrime[maxValue];
  for (int i = 0; i < maxValue; i++) { isPrime[i] = 1; }

  for (int i = 2; i <= sqrt(maxValue); i++) {
    if (isPrime[i]) {
      for (int multiple = pow(i, 2); multiple < maxValue; multiple += i) {
        isPrime[multiple] = 0;
      }
    }
  }

  int maxPrime = 0;
  for (int i = 2, primeCount = 0; i < maxValue && primeCount < n; i++) {
    if (isPrime[i]) {
      maxPrime = i;
      primeCount++;
    }
  }
  return maxPrime;
}

int main() {
  printf("%d", findNthPrimeUpTo(10001, 200000));
  return 0;
}
