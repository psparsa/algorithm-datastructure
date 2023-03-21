#include <iostream>
#include <time.h>
using namespace std;

template<typename T, int n>
void
printArray(T const (&l)[n])
{
  for (int x = 0; x < n; ++x)
    cout << l[x] << ", ";
}

void
fisherYatesShuffle(int l[], int n, int i = -1)
{
  if (i == -1) {
    fisherYatesShuffle(l, n, n - 1);
    srand(time(0));
  } else if (i > 1) {
    swap(l[i], l[rand() % i]);
    fisherYatesShuffle(l, n, i - 1);
  }
}

int
main()
{
  int sortedArr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  cout << "Sorted array:" << endl;
  printArray(sortedArr);
  cout << endl << endl << "Shuffled array:" << endl;
  fisherYatesShuffle(sortedArr, 10);
  printArray(sortedArr);
  cout << endl;
  return 0;
}
