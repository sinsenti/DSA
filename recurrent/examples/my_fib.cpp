#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> a(n + 1);

  a[0] = 0;
  a[1] = 1;
  for (int i = 2; i <= n; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }
  cout << a[n];
  return 0;
}
