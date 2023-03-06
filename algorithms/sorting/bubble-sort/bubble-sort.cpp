#include <iostream>

void
bubbleSort(int a[], int l)
{
    for (int x = 0; x < l - 1; ++x) {
    int s = true;
    for (int y = 0; y < l - x - 1; ++y) {
        int current = a[y];
        int next = a[y + 1];

        if (current > next) {
          a[y + 1] = current;
          a[y] = next;
          s = false;
        }
    }
    if (s)
      break;
    }
}

void
printArray(int a[], int l)
{
  int x = 0;
  while (x < l) {
    std::cout << a[x];
    std::cout << ", ";
    ++x;
  }
}


int main()
{
  //int arr[] = { 6, 4, 8, 3, 2, 9, 0, 1, 7, 6, 5 };
  int arr[] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
  int arrLength = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Input Array:" << std::endl;
  printArray(arr, arrLength);
  std::cout << std::endl << std::endl;
  std::cout << "Output Array:" << std::endl;
  bubbleSort(arr, arrLength);
  printArray(arr, arrLength);

  return 0;
}