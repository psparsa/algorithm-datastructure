#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int datasetArr[] = {61, 74, 9,  4,  95, 2, 81, 48,
                           14, 94, 33, 71, 84, 7, 1,  0};
void insertionSort(int arr[], size_t arrLength, char *direction);
bool shouldSwap(int a, int b, char *direction);
void swap(int *a, int *b);
void printArr(int arr[], size_t arrLength);

int main() {
  const size_t arrSize = sizeof(datasetArr) / sizeof(datasetArr)[0];
  printf("Input:\n");
  printArr(datasetArr, arrSize);

  insertionSort(datasetArr, arrSize, "ASC");

  printf("Output:\n");
  printArr(datasetArr, arrSize);
  return 0;
}

void insertionSort(int arr[], size_t arrLength, char *direction) {
  if (arrLength < 2)
    return;

  for (size_t j = 1; j < arrLength; j++) {
    const int currentVal = arr[j];
    int prevPointer = j - 1;

    while (prevPointer >= 0 &&
           shouldSwap(arr[prevPointer], currentVal, direction)) {
      swap(&arr[prevPointer], &arr[prevPointer + 1]);
      prevPointer--;
    }
  }
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