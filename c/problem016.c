/*
* 2^15 = 32768 and the sum of its digits is 3+2+7+6+8 = 26
* What is the sum of the digits of the number 2^1000?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{   
  const int ARRAY_LEN = 350;
  const int POWER = 1000;

  int result[ARRAY_LEN] = {0};
  result[0] = 1; // starting at 2^0 to make any debugging easier.

  for (int n = 1; n <= POWER; n++) {
    for (int i = 0; i < ARRAY_LEN; i++) {
      result[i] <<= 1;
      if (i > 0 && result[i-1] >= 10 ) {
        result[i-1] -= 10;
        result[i] += 1;
      }
    }
  }

  unsigned long sum = 0;
  for (int n = ARRAY_LEN-1; n >= 0; n--) {
    sum += result[n];
  }

  printf("%lu\n", sum);
  return 0;
}
