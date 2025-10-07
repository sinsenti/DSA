#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

short main() {
  short n;
  cin >> n;

  vector<short> a(n), b(n);
  for (short i = 0; i < n; i++)
    cin >> a[i];
  for (short i = 0; i < n; i++)
    cin >> b[i];

  vector<vector<short>> dp(n + 1, vector<short>(n + 1, 0));

  for (short i = 1; i <= n; i++) {
    for (short j = 1; j <= n; j++) {
      if (a[i - 1] == b[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  short result = dp[n][n];
  vector<short> idxA, idxB;
  short i, j;
  i = j = n;

  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      idxA.push_back(i - 1);
      idxB.push_back(j - 1);
      i--;
      j--;
    } else {
      if (dp[i - 1][j] > dp[i][j - 1]) {
        i--;
      } else {
        j--;
      }
    }
  }

  reverse(idxA.begin(), idxA.end());
  reverse(idxB.begin(), idxB.end());

  cout << result << "\n";
  for (short x : idxA)
    cout << x << " ";
  cout << "\n";
  for (short x : idxB)
    cout << x << " ";
  cout << "\n";

  return 0;
}
