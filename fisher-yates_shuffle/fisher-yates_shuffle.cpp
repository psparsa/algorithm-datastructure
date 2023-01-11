#include <iostream>
#include <random>
using namespace std;

template<typename T, int n>
void
printArray(T const (&arr)[n])
{
  for (int x = 0; x < n; ++x)
    cout << arr[x] << ", ";
}

void
fisherYatesShuffle(int l[], int n, int i = -1)
{
  if (i == -1)
    fisherYatesShuffle(l, n, n - 1);
  else if (i > 1) {
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(0, i);
    int r = distr(generator);
    int t = l[i];
    l[i] = l[r];
    l[r] = t;
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
  return 0;
}
