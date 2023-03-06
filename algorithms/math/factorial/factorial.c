#include <stdio.h>
#include <stdlib.h>

unsigned long long factorial(int num);

int main() {
  unsigned long long answer = factorial(10);
  printf("%llu\n", answer);
  return 0;
}

unsigned long long factorial(int num) {
  unsigned long long tmp = 1;
  for (int l = 1; l <= num; l++)
    tmp = tmp * l;
  return tmp;
}