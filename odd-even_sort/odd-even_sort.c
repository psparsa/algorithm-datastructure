#include <stdbool.h>
#include <stdio.h>

void printAray(int arr[], int n) {
  int x = 0;
  while (x < n) {
    printf("%i,", arr[x]);
    ++x;
  }
  printf("\n");
}

void handleSwap(int arr[], int i, bool *isSorted) {
  if (arr[i] > arr[i + 1]) {
    int tmp = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = tmp;
    *isSorted = false;
  }
}

void oddEvenSort(int arr[], int n) {
  bool isSorted = false;

  while (!isSorted) {
    isSorted = true;

    for (int i = 1; i < n - 1; i = i + 2)
      handleSwap(arr, i, &isSorted);
    for (int i = 0; i < n - 1; i = i + 2)
      handleSwap(arr, i, &isSorted);
  }
}

int main() {
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Input\n");
  printAray(arr, n);
  oddEvenSort(arr, n);
  printf("Output\n");
  printAray(arr, n);
  return 0;
}
