#include <stdio.h>

int list[] = {2, 56, 66, 51, 82, 512, 92, 3, 8, 5, 8, 0, 11, 36, 437};
void gnomeSort(int l[], int s);
void printArr(int arr[], size_t arrLength);

int main() {
  int listSize = sizeof(list) / sizeof(list[0]);
  gnomeSort(list, listSize);
  printArr(list, listSize);
  return 0;
}

void gnomeSort(int l[], int s) {
  if (s < 2)
    return;
  int p = 1;
  while (p < s)
    if (p == 0)
      ++p;
    else if (l[p] < l[p - 1]) {
      int t = l[p];
      l[p] = l[p - 1];
      l[p - 1] = t;
      --p;
    } else
      ++p;
}

void printArr(int arr[], size_t arrLength) {
  for (int x = 0; x < arrLength; x++)
    printf("%i, ", arr[x]);
  printf("\n");
}