/*
 * If the numbers 1 to 5 are written out in words: one, two, three, four, five,
 * then there are 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 */

#include <stdio.h>

char *ones(int num);
char *teens(int num);
char *tens(int num);
char *hundreds(int num);

int main() {
  char result[100000];
  int offset = 0;

  for (int i = 1; i <= 1000; i++) {
    int remainder = i;
    if (remainder == 1000) {
      offset +=
          snprintf(result + offset, sizeof(result) - offset, "onethousand");
      remainder %= 1000;
    }

    if (remainder >= 100) {
      offset += snprintf(result + offset, sizeof(result) - offset, "%s",
                         hundreds(remainder));
      remainder %= 100;
      if (remainder) {
        offset += snprintf(result + offset, sizeof(result) - offset, "and");
      }
    }

    if (remainder >= 20) {
      offset += snprintf(result + offset, sizeof(result) - offset, "%s",
                         tens(remainder));
      remainder %= 10;
    }

    if (remainder >= 10) {
      offset += snprintf(result + offset, sizeof(result) - offset, "%s",
                         teens(remainder));
      remainder = 0;
    } else {
      offset += snprintf(result + offset, sizeof(result) - offset, "%s",
                         ones(remainder));
    }
  }

  printf("%i\n", offset);
  return 0;
}

char *ones(int num) {
  switch (num) {
  case 1:
    return "one";
  case 2:
    return "two";
  case 3:
    return "three";
  case 4:
    return "four";
  case 5:
    return "five";
  case 6:
    return "six";
  case 7:
    return "seven";
  case 8:
    return "eight";
  case 9:
    return "nine";
  default:
    return "";
  }
}

char *teens(int num) {
  switch (num) {
  case 10:
    return "ten";
  case 11:
    return "eleven";
  case 12:
    return "twelve";
  case 13:
    return "thirteen";
  case 14:
    return "fourteen";
  case 15:
    return "fifteen";
  case 16:
    return "sixteen";
  case 17:
    return "seventeen";
  case 18:
    return "eighteen";
  case 19:
    return "nineteen";
  default:
    return "";
  }
}

// tens
char *tens(int num) {
  switch (num / 10) {
  case 2:
    return "twenty";
  case 3:
    return "thirty";
  case 4:
    return "forty";
  case 5:
    return "fifty";
  case 6:
    return "sixty";
  case 7:
    return "seventy";
  case 8:
    return "eighty";
  case 9:
    return "ninety";
  default:
    return "";
  }
}

// hundreds
char *hundreds(int num) {
  switch (num / 100) {
  case 1:
    return "onehundred";
  case 2:
    return "twohundred";
  case 3:
    return "threehundred";
  case 4:
    return "fourhundred";
  case 5:
    return "fivehundred";
  case 6:
    return "sixhundred";
  case 7:
    return "sevenhundred";
  case 8:
    return "eighthundred";
  case 9:
    return "ninehundred";
  default:
    return "";
  }
}
