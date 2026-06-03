/*
* Using names.txt, a 46K text file containing over five-thousand first names,
* begin by sorting it into alphabetical order. Then working out the
* alphabetical value for each name, multiply this value by its alphabetical
* position in the list to obtain a name score.
*
* For example, when the list is sorted into alphabetical order, COLIN, which is
* worth 3+15+12+9+14 = 53, is the 938th name in the list. So, COLIN would
* obtain a score of 938 x 53 = 49714.

* What is the total of all the name scores in the file?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 10000

int comparator(const void *a, const void *b) {
  return strcmp((const char *)a, (const char *)b);
}

int main() {

  FILE *fp = fopen("../data_files/names.txt", "r");
  if (fp == NULL) {
    printf("Can't open file\n");
    return 1;
  }

  char names[MAX_NAMES][50];
  char name[50];
  int numNames = 0;
  while (fscanf(fp, "\"%49[^\"]\"", name) == 1) {
    strcpy(names[numNames], name);
    fscanf(fp, "%*c"); // discard comma
    numNames++;
  }

  fclose(fp);

  qsort(names, numNames, sizeof(names[0]), comparator);

  int score = 0;
  for (int i = 0; i < numNames; i++) {
    char c = names[i][0];
    for (int j = 0; names[i][j] != '\0'; j++) {
      int alphabetPosition = (names[i][j] - 'A' + 1);
      int listPosition = i + 1;
      score += alphabetPosition * listPosition;
    }
  }

  printf("%i\n", score);
  return 0;
}
