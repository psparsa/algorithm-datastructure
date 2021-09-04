#include <stdio.h>

int binarySearch(const int arr[], int arrLength, int target, int start, int end);
int getMiddleOfRange(int start, int end);

int main() {
  const int sortedArr[] = {10, 17, 32, 83, 534, 865, 976, 1025, 1535, 1921};
  const int sizeOfArr = sizeof(sortedArr) / sizeof(sortedArr[0]);
  const int target = 1535;
  const int result = binarySearch(sortedArr, sizeOfArr, target, -1, -1);

  printf("Result: %d\n", result);
}

int binarySearch(const int arr[], int arrLength, int target, int start, int end) {
  const int startPointer = start > -1 ? start : 0;
  const int endPointer = end > -1 ? end : arrLength;

  if (arrLength < 2)
    return 0;

  if (startPointer < endPointer) {
    const int middlePointer = getMiddleOfRange(startPointer, endPointer);

    if (arr[middlePointer] == target)
      return middlePointer;

    if (arr[middlePointer] > target)
      return binarySearch(arr, arrLength, target, startPointer, middlePointer - 1);
    if (arr[middlePointer] < target)
      return binarySearch(arr, arrLength, target, middlePointer + 1, endPointer);
  }

  return -1;
}

int getMiddleOfRange(int start, int end) { return (end - start) / 2 + start; }