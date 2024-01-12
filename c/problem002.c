// By considering the terms in the Fibonacci sequence whose values
// do not exceed four million, find the sum of the even-valued terms.

#include <stdio.h>

int main() {
  int x = 1, y = 2, sumOfEvens = 2;

  while (y <= 4000000) {
    // Doing a little math for fun to avoid having a separate "sum" variable 
    // for calculating fibonacci :)
    y = x+y;
    x = y-x;
    sumOfEvens += x+y % 2 ? 0 : x+y;
  }

  printf("%d\n", sumOfEvens);
  return 0;
}
