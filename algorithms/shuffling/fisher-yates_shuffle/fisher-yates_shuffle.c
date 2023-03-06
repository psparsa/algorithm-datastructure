#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArr(int arr[], size_t arrLength) {
  for (int x = 0; x < arrLength; x++)
    printf("%i, ", arr[x]);
  printf("\n");
}

void fisherYatesShuffle(int list[], int length) {
  int j = length - 1;
  while (j > 0) {
    int r = rand() % j;
    int t = list[j];
    list[j] = list[r];
    list[r] = t;
    --j;
  }
}

int main() {
  srand(time(0));
  int list[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int length = sizeof(list) / sizeof(int);
  printArr(list, length);
  fisherYatesShuffle(list, length);
  printArr(list, length);
  return 0;
}