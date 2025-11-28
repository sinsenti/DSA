#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  string line;
  int n;
  int m;
  fin >> n;
  fin >> m;
  int el1, el2;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < m; i++) {
    fin >> el1 >> el2;
    a[el1 - 1][el2 - 1] = 1;
    a[el2 - 1][el1 - 1] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fout << a[i][j] << ' ';
    }
    fout << '\n';
  }

  fin.close();
  fout.close();
  return 0;
}
