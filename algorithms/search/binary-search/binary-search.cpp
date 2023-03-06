#include <iostream>
using namespace std;

int binarySearch(const int arr[], int length, int target, int start = -1,
                 int end = -1) {
  int startPointer = start > -1 ? start : 0;
  int endPointer = end > -1 ? end : length;
  
  if (length < 2) return 0;
  if (startPointer < endPointer) {
    int middlePointer = (endPointer - startPointer) / 2 + startPointer;
    if (arr[middlePointer] == target) return middlePointer;
    if (arr[middlePointer] > target)
      return binarySearch(arr, length, target, startPointer, middlePointer - 1);
    if (arr[middlePointer] < target)
      return binarySearch(arr, length, target, middlePointer + 1, endPointer);
  }

  return -1;
}

int main() {
  int arr[] = {10, 17, 32, 83, 534, 865, 976, 1025, 1535, 1921};
  int result = binarySearch(arr, 10, 15235);
  if (result == -1)
    cout << "the target value is not in the array";
  else
    cout << "Result: " << result << endl;
}