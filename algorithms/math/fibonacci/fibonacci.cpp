#include <iostream>
#include <map>
using namespace std;

#define ll long long

map<int, ll> memoMap;

ll
fib(int n)
{
  ll tmp;

  if (n <= 1)
    return n;

  if (memoMap.find(n) != memoMap.end())
    return memoMap[n];

  else {
    tmp = fib(n - 1) + fib(n - 2);
    memoMap[n] = tmp;
    return tmp;
  }
}

int
main()
{
  int n = 43;

  cout << fib(n) << endl;
}