#include <iostream>
using namespace std;

void
shellSort(int arr[], int n)
{
  int g = n / 2;
  while (g > 0) {
    for (int i = g; i < n; i += 1) {
      int tmp = arr[i], x;
      for (x = i; x >= g && arr[x - g] > tmp; x = x - g)
        arr[x] = arr[x - g];
      arr[x] = tmp;
    }
    g = g / 2;
  }
}

int
main()
{
  int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Input:" << endl;
  for (int i : arr) 
    cout << i << ", ";
  shellSort(arr, n);
  cout << endl << "Output:" <<endl;
  for (int i : arr) 
    cout << i << ", ";
  return 0;
}
