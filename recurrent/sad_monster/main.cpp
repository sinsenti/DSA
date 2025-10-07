#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  double a, b, c, d;
  cin >> n;
  cin >> a >> b >> c >> d;

  vector<double> dp(n + 2, 0.0);
  dp[1] = 1.0;

  for (int i = 1; i <= n; i++) {
    vector<double> next(n + 2, 0.0);
    next[0] = dp[0] + dp[1] * (c - d);

    for (int x = 1; x <= n + 1; x++) {
      if (dp[x] == 0.0)
        continue;
      double p_up = a + b / x;
      double p_down = c - d / x;
      double p_stay = 1.0 - p_up - p_down;

      if (x + 1 <= n + 1) {
        next[x + 1] += dp[x] * p_up;
      }
      if (x > 1) {
        next[x - 1] += dp[x] * p_down;
      }
      next[x] += dp[x] * p_stay;
    }

    cout << fixed << setprecision(15) << next[0] << endl;
    dp = next;
  }

  return 0;
}
