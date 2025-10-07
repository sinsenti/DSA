#include <iostream>
#include <vector>
using namespace std;

// Лягушки:
// дп:
// b[1] = a[1]
// b[2] = -1
// b[3] = b[1] + 1[3]
//
// b[i] = max(b[i-2], b[i-3]) + a[i]
// 6 1 100 3 4 1000 0

vector<int> dp;

void solution(int n, vector<int> a) {

  dp[0] = a[0];
  dp[1] = -1;

  for (int i = 4; i < n; i++) {
    dp[i] = max(a[i - 2], a[i - 3]) + a[i];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  vector<int> input;
  int el;
  for (int i = 0; i < n; i++) {
    cin >> el;
    input.push_back(el);
  }
  input[1] = -1;

  if (n == 1) {
    cout << input[0] << '\n';
    return 0;
  }

  if (n <= 2) {
    cout << -1 << '\n';
    return 0;
  }
  dp.resize(n + 1, -1);
  solution(n, input);

  cout << dp[n] << '\n';
  for (int i = 0; i < n; i++) {
    if (dp[i] != -1) {
      cout << dp[i];
    }
  }

  return 0;
}
