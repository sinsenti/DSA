#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int s;

  ifstream f("input.txt");
  ofstream fout("output.txt");
  f >> s;

  vector<int> dim(s + 1);

  for (int i = 0; i < s; i++) {
    int rows, cols;
    f >> rows >> cols;
    if (i == 0) {
      dim[i] = rows;
    }
    dim[i + 1] = cols;
  }

  vector<vector<int>> dp(s, vector<int>(s, 0));

  for (int len = 2; len <= s; len++) {
    for (int i = 0; i <= s - len; i++) {
      int j = i + len - 1;
      dp[i][j] = 1e+9;

      for (int k = i; k < j; k++) {
        int cost = dp[i][k] + dp[k + 1][j] + dim[i] * dim[k + 1] * dim[j + 1];
        if (cost < dp[i][j]) {
          dp[i][j] = cost;
        }
      }
    }
  }

  fout << dp[0][s - 1] << endl;
  f.close();
  fout.close();

  return 0;
}
