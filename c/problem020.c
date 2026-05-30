/*
 * Find the sum of the digits in the number 100 factorial.
 */

#include <stdio.h>

#define ARRAY_LEN 200

int factorial_sum(int n) {
  int arr[ARRAY_LEN] = {0};
  arr[ARRAY_LEN - 1] = 1;

  for (int fact = n; fact > 1; fact--) {
    int carry = 0;
    for (int i = ARRAY_LEN - 1; i > 0; i--) {
      int product = arr[i] * fact;
      arr[i] = (product + carry) % 10;

      carry = (product + carry) / 10;
    }
  }

  int sum = 0;
  for (int i = 0; i < ARRAY_LEN; i++) {
    sum += arr[i];
  }

  return sum;
}

int main() {
  printf("%i\n", factorial_sum(100));
  return 0;
}
