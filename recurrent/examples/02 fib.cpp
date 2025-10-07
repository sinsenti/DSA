#include <iostream>
#include <vector>
using namespace std;

vector<long long> b;

long long fib_m(int x) {
  if (b[x] == -1)
    b[x] = fib_m(x - 1) + fib_m(x - 2);
  return b[x];
}

int main() {
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  a[0] = 0;
  a[1] = 1;
  for (int i = 2; i <= n; i++)
    a[i] = a[i - 1] + a[i - 2];
  cout << a[n] << endl;
  b.resize(n + 1, -1);
  b[0] = 0;
  b[1] = 1;
  cout << fib_m(n) << endl;
  return 0;
}
