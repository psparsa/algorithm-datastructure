#include <stdio.h>
#include <stdlib.h>

int factorial(int num);

int main() {
  int answer = factorial(10);
  printf("%i\n", answer);
  return 0;
}

int factorial(int num) {
  int tmp = 1;
  for (size_t l = 1; l <= num; l++)
    tmp = tmp * l;
  return tmp;
}