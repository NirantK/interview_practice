#include <cstdio>
using namespace std;
long long abs(long long x) {
  return x > 0 ? x : -x;
}

int main(void) {
  long long a, b;
  while (scanf("%lld%lld", &a, &b) == 2)
    printf("%lld\n", abs(a-b));
  return 0;
}