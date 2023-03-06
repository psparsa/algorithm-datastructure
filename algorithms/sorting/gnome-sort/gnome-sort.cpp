#include <iostream>
using namespace std;

void gnomeSort(int l[], size_t n) {
  if (n < 2) return;
  size_t p = 1;
  while (p < n) {
    if (p == 0) {
      ++p;
    } else if (l[p] < l[p - 1]) {
      swap(l[p], l[p - 1]);
      --p;
    } else {
      ++p;
    }
  }
}

int main() {
  int list[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  gnomeSort(list, 10);
  for (int x : list) cout << x << ", ";
  return 0;
}
