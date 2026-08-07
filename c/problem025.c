/*
 * What is the index of the first term in the Fibonacci sequence to contain
 * 1000 digits
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sumBigIntArray(int *a, int *b, int *sum, size_t len) {
  int carry = 0;
  for (size_t i = 0; i < len; i++) {
    int total = a[i] + b[i] + carry;
    sum[i] = total % 10;
    carry = total / 10;
  }
}

int main() {
  int firstTerm[1000] = {0};
  firstTerm[0] = 1;
  int secondTerm[1000] = {0};
  secondTerm[0] = 2;

  int index = 3;

  int sum[1000];
  while (secondTerm[999] == 0) {
    sumBigIntArray(firstTerm, secondTerm, sum, 1000);
    memcpy(firstTerm, secondTerm, 1000 * sizeof(int));
    memcpy(secondTerm, sum, 1000 * sizeof(int));
    index++;
  }

  printf("%i\n", index);

  return EXIT_SUCCESS;
}
