#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<ll> vec;

ll
fib(int n)
{

  if (n <= 2)
    return n;

  else {
    vec.clear();
    vec.push_back(1);
    vec.push_back(1);

    for (int i = 2; i < n; ++i)
      vec.push_back(vec.at(i - 2) + vec.at(i - 1));

    return vec.at(n - 1);
  }
}

int
main()
{
  int n = 80;

  cout << fib(n) << endl;
}