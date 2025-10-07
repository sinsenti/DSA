#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (n == 1) {
    cout << a[0] << "\n1\n";
    return 0;
  }

  if (n == 2) {
    cout << -1 << '\n';
    return 0;
  }

  vector<long long> dp;
  dp.resize(n, -1);
  vector<int> parent(n, -1);

  dp[0] = a[0];
  dp[1] = -1;
  dp[2] = a[0] + a[2];
  parent[2] = 0;

  for (int i = 3; i < n; i++) {
    int from2 = dp[i - 2];
    int from3 = dp[i - 3];

    if (from2 == -1 && from3 == -1) {
      dp[i] = -1;
      parent[i] = -1;
    } else if (from2 >= from3) {
      dp[i] = from2 + a[i];
      parent[i] = i - 2;
    } else {
      dp[i] = from3 + a[i];
      parent[i] = i - 3;
    }
  }

  if (dp[n - 1] == -1) {
    cout << -1 << "\n";
    return 0;
  }

  cout << dp[n - 1] << "\n";

  vector<int> path;
  int cur = n - 1;
  while (cur >= 0) {
    path.push_back(cur + 1);
    cur = parent[cur];
  }
  reverse(path.begin(), path.end());

  int n_path = path.size();

  for (int i = 0; i < n_path - 1; i++) {
    cout << path[i] << ' ';
  }
  cout << path[n_path - 1] << '\n';

  return 0;
}
