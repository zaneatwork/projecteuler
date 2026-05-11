/*
* Starting in the top left corner of a 2 x 2 grid, and only being able to move 
* to the right and down, there are exactly 6 routes to the bottom right corner.
*
* How many such routes are there through a 20 x 20 grid?
*/

#include <stdio.h>
#include <math.h>

long double factorial(int n) {
  long double fact = 1;
  for (int i = 1; i <= n; i++) {
    fact *= i;
  }
  return fact;
}

/*
* The formula for the number of contigous routes for a (n*n) square grid is
* (2n)! / (n! * n!)
* This is also the center of the 2*nth row of pascal's triangle.
* So for 2x2 grid, it would be the middle of the 4th row (6) and so on.
*/
int main() {
  long double result = factorial(2*20) / powl(factorial(20), 2);
  printf("%.0Lf\n", result);
  return 0;
}

