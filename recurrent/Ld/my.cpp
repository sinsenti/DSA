#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream f("in.txt");
  ofstream fout("out.txt");

  int x, y, z;
  string A, B;
  f >> x >> y >> z >> A >> B;

  int n = A.size();
  int m = B.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    dp[i][0] = i * x;
  }
  for (int j = 1; j <= m; j++) {
    dp[0][j] = j * y;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int isEqual = int(A[i - 1] == B[j - 1]);
      if (A[i - 1] == B[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] =
            min(dp[i - 1][j - 1] + z, min(dp[i - 1][j] + x, dp[i][j - 1] + y));
      }
    }
  }

  fout << dp[n][m];

  f.close();
  fout.close();
  return 0;
}
