#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int binpow(int a, int n) {
  int res = 1;
  while (n != 0) {
    if (n & 1)
      res = (int)((long long)res * a % mod);
    a = (int)((long long)a * a % mod);
    n >>= 1;
  }
  return res;
}

int inv(int x) { return binpow(x, mod - 2); }

int binomialCoeff(int n, int k) {
  if (k > n)
    return 0;
  if (k > n - k)
    k = n - k;

  long long res = 1;
  for (int i = 1; i <= k; ++i) {
    res = (res * (n - k + i)) % mod;
    res = (res * inv(i)) % mod;
  }
  return (int)res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K;
  cin >> N >> K;
  cout << binomialCoeff(N, K) << "\n";

  return 0;
}
