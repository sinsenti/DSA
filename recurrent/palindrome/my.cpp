#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  string a;
  getline(fin, a);
  short n = (short)a.size();
  string b = a;
  reverse(b.begin(), b.end());

  vector<vector<short>> dp(n + 1, vector<short>(n + 1, 0));
  for (short i = 1; i <= n; i++) {
    for (short j = 1; j <= n; j++) {
      if (a[i - 1] == b[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  short length = dp[n][n];

  short i = n, j = n;
  vector<short> idxA;
  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      idxA.push_back(i - 1);
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1])
      i--;
    else
      j--;
  }
  string result;
  for (short x : idxA) {
    result += a[x];
  }

  fout << length << '\n' << result << '\n';

  fin.close();
  fout.close();
  return 0;
}
