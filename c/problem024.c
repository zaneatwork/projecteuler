/*
 * What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4,
 * 5, 6, 7, 8 and 9?
 */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void findLexicographicPermutationAtIndex(int *nums, size_t len, int index,
                                         int *output) {
  // assume the digits are pre-sorted

  if (len == 1) {
    output[0] = nums[0];
    return;
  }

  int numPermutations = 1;
  for (int i = len; i > 0; i--) {
    numPermutations *= i;
  }

  int permutationsPerIndex = numPermutations / len;
  int indexOfFirstDigit = index / permutationsPerIndex;
  int firstDigit = nums[indexOfFirstDigit];

  output[0] = firstDigit;

  int remainingNums[len - 1];

  int numsIndex = 0;
  int remainingNumsIndex = 0;
  while (remainingNumsIndex < (len - 1)) {
    int nextValue = nums[numsIndex];
    if (nextValue != firstDigit) {
      remainingNums[remainingNumsIndex] = nextValue;
      remainingNumsIndex++;
    }
    numsIndex++;
  }

  int subindex = index % permutationsPerIndex;

  findLexicographicPermutationAtIndex(remainingNums, len - 1, subindex,
                                      output + 1);
}

int main() {
  int nums[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  int permutation[10];

  findLexicographicPermutationAtIndex(nums, 10, 1000000 - 1, permutation);

  for (int i = 0; i < 10; i++) {
    printf("%d", permutation[i]);
  }

  return 0;
}
