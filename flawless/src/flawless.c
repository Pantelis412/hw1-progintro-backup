#include <math.h>
#include <stdio.h>
#include <stdlib.h>
long long int one_digit(long long int n) {
  long long int sum = 0;
  int tmp;
  while (n > 0) {
    tmp = (n % 10);
    sum += tmp;
    n /= 10;
  }
  return sum * sum;
}
int main(int argc, char **argv) {
  if (argc != 3) {
    printf("The programm must be called as ./flawless low high\n");
    return 1;
  }
  long long int low = atoll(argv[1]);
  long long int high = atoll(argv[2]);
  if (high < low) return 1;
  if (low < 1 || high > 1e+12) return 1;
  long long int sum = 0;
  for (long long int i = (ceil(sqrt(low))); i <= (floor(sqrt(high))); i++) {
    if ((i * i) == one_digit(i * i)) {
      sum += (i * i);
    }
  }
  printf("%lld\n", sum);
  return 0;
}