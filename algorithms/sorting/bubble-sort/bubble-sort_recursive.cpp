#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
  if (n == 1) return;

  bool isSorted = true;
  for (int i = 0; i < n - 1; ++i)
    if (arr[i] > arr[i + 1]) {
      swap(arr[i], arr[i + 1]);
      isSorted = false;
    }

  if (isSorted) return;
  else bubbleSort(arr, n - 1);
}

int main() {
  int arr[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int arrLength = sizeof(arr) / sizeof(arr[0]);

  std::cout << "Input Array:" << std::endl;
  for (int x : arr) cout << x << ", ";
  std::cout << std::endl << std::endl;
  std::cout << "Output Array:" << std::endl;
  bubbleSort(arr, arrLength);
  for (int x : arr) cout << x << ", ";

  return 0;
}