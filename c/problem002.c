// By considering the terms in the Fibonacci sequence whose values
// do not exceed four million, find the sum of the even-valued terms.

#include <stdio.h>

int main() {
  int firstTerm = 1, secondTerm = 2;
  int sum, prevSum;
  int sumOfEvens = 2;

  while (prevSum < 4000000) {
    prevSum = sum;
    sum = firstTerm + secondTerm;
    firstTerm = secondTerm;
    secondTerm = sum;

    sumOfEvens += sum % 2 ? 0 : sum;
  }

  printf("%d\n", sumOfEvens);
  return 0;
}
