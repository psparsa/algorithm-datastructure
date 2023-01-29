#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
  if (n < 2) return;
  for (int i = 1; i < n; ++i) {
    int c = arr[i];
    int p = i - 1;
    while (p >= 0 && arr[p] > c) {
      swap(arr[p], arr[p + 1]);
      --p;
    }
  }
}

int main() {
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int length = sizeof(arr) / sizeof(int);
  cout << "Input: " << endl;
  for (int x : arr) {
    cout << x << ", ";
  }
  insertionSort(arr, length);
  cout << endl << endl << "Output: " << endl;
  for (int x : arr) {
    cout << x << ", ";
  }
  cout << endl;

  return 0;
}