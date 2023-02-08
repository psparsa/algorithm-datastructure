#include <stdio.h>

void shellSort(int arr[], int n) {
  int gap = n / 2;

  while (gap > 0) {
    for (int i = gap; i < n; i += 1) {
      int tmp = arr[i], x = i;
      for (; x >= gap && arr[x - gap] > tmp; x -= gap) arr[x] = arr[x - gap];
      arr[x] = tmp;
    }

    gap /= 2;
  }
}

int main() {
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Input\n");
  for (int i : arr) printf("%i,", i);

  shellSort(arr, n);

  printf("\nOutput\n");
  for (int i : arr) printf("%i,", i);

  return 0;
}
