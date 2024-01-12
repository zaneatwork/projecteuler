// A palindromic number reads the same both ways.
// The largest palindrome made from the product of two -digit numbers is
// 9009 = 91 * 99
// Find the largest palindrome made from the product of two 3-digit numbers.

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int n) {
  int numDigits = log10(n) + 1;
  bool palindrome = true;

  for (int i = 0; i < numDigits / 2; i++) {
    palindrome &= ((n / (int)pow(10, i) % 10) ==
                   (n / (int)pow(10, numDigits - (i + 1)) % 10));
  }
  return palindrome;
}

int main() {
  int maxPal = 0;

  for (int x = 100; x < 999; x++) {
    for (int y = x; y < 999; y++) {
      maxPal = isPalindrome(x * y) && x * y > maxPal ? x * y : maxPal;
    }
  }
  printf("%d\n", maxPal);
  return 0;
}
