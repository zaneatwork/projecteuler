// What is the largest prime factor of the number 600851475143?
#include <stdio.h>

int main() {
  long long n = 600851475143;

  // n is odd so we only need to check for odd factors
  for (long long i = 3; i * i <= n; i += 2) {
    while (n % i == 0) {
      n /= i;
    }
  }

  printf("%lld\n", n);

  return 0;
}
