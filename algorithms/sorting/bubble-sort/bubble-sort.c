#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int datasetArr[] = {25, 45, 1,  33, 68, 13, 57, 15,
                           85, 15, 83, 10, 6,  8,  2};
void bubbleSort(int arr[], size_t arrLength, char *direction);
bool shouldSwap(int a, int b, char *direction);
void swap(int *a, int *b);
void printArr(int arr[], size_t arrLength);

int main() {
  const size_t arrSize = sizeof(datasetArr) / sizeof(datasetArr)[0];
  printf("Input:\n");
  printArr(datasetArr, arrSize);

  bubbleSort(datasetArr, arrSize, "ASC");

  printf("Output:\n");
  printArr(datasetArr, arrSize);
  return 0;
}

void bubbleSort(int arr[], size_t arrLength, char *direction) {
  bool isSorted = false;

  while (!isSorted) {
    isSorted = true;
    for (int y = 0; y < (arrLength - 1); y++) {
      if (shouldSwap(arr[y], arr[y + 1], direction)) {
        swap(&arr[y], &arr[y + 1]);
        isSorted = false;
      }
    }
  };
}

bool shouldSwap(int a, int b, char *direction) {
  if (strcmp(direction, "ASC") == 0) {
    return a > b;
  }
  return a < b;
}

void swap(int *a, int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

void printArr(int arr[], size_t arrLength) {
  for (int x = 0; x < arrLength; x++)
    printf("%i, ", arr[x]);
  printf("\n");
}