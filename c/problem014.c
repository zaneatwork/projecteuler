/*
* The following iterative sequence is defined for the set of positive integers:
* n -> n/2 (if n even)
* n -> 3n+1 (if n is odd)
* 13, 40, 20, 10, 5, 16, 8, 4, 2, 1
*
* It can be seen that this sequence (starting at 13 and finishing at 1) contains 
* 10 terms. Although it has not been proved yet (Collatz Problem), 
* it is thought that all starting numbers finish at 1.
*
* Which starting number, under one million, produces the longest chain?
*
* NOTE: Once the chain starts the terms are allowed to go above one million.
*/
#include <stdio.h>

int main() {

  unsigned long maxCount = 0;
  unsigned long bestVal = 0;

  for (unsigned long startingVal = 1; startingVal < 1000000; startingVal++) {
    unsigned long val = startingVal;
    unsigned int count = 1;

    while (val > 1) {
      if (val % 2 == 0) {
        val = val / 2;
      } else {
        val = val * 3 + 1;
      }
      count++;
    }

    if (count > maxCount) {
      bestVal = startingVal;
      maxCount = count;
    }
  }

  printf("Longest sequence comes from: %lu, %lu elements\n", bestVal, maxCount);

  return 0;
}
