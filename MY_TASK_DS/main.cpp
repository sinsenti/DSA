#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int N = 101;
vector<vector<int>> own(N, vector<int>(N, 0));
vector<vector<bool>> ctrl(N, vector<bool>(N, false));

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int a, b, p;
  while (fin >> a >> b >> p) {
    own[a][b] += p;
  }

  set<pair<int, int>> result;

  for (int i = 1; i < N; ++i) {
    vector<int> sum(N, 0);
    queue<int> q;

    for (int j = 1; j < N; ++j) {
      sum[j] = own[i][j];
    }

    for (int j = 1; j < N; ++j) {
      if (i != j && sum[j] > 50 && !ctrl[i][j]) {
        ctrl[i][j] = true;
        q.push(j);
        result.insert({i, j});
      }
    }

    while (!q.empty()) {
      int c = q.front();
      q.pop();

      for (int j = 1; j < N; ++j) {
        if (c == j)
          continue;
        sum[j] += own[c][j];
        if (i != j && sum[j] > 50 && !ctrl[i][j]) {
          ctrl[i][j] = true;
          q.push(j);
          result.insert({i, j});
        }
      }
    }
  }

  for (auto &pr : result) {
    fout << pr.first << " " << pr.second << "\n";
  }

  return 0;
}
