// A Pythagorean triplet is a set of three natural numbers, a < b < c, for
// which, a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 5^2
// There exists exactly one Pythagorean triplet for which a + b + c = 1000
// Find the product abc

#include <math.h>
#include <stdio.h>

int main() {
  for (int a = 1; a < 1000; a++) {
    for (int b = a + 1; b < 1000 - a; b++) {
      double cWithDecimal = sqrt(a * a + b * b);
      int c = (int)cWithDecimal;
      if (c < cWithDecimal) {
        continue;
      }
      if (a + b + c == 1000) {
        printf("%d\n", a * b * c);
        return 0;
      }
    }
  }

  return -1;
}
