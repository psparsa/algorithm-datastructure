#include <iostream>

unsigned long long
factorial(unsigned long long num)
{
   if (num == 1)
     return num;
   return factorial(num - 1) * num;
}

int
main()
{
  unsigned long long num = 50;
  unsigned long long answer = factorial(num);
  printf("%llu\n", answer);
  return 0;
}
