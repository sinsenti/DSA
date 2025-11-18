#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int m, c, n;
  fin >> m >> c >> n;
  vector<int> table(m, -1);
  unordered_set<int> used;

  for (int j = 0; j < n; ++j) {
    int key;
    fin >> key;
    if (used.count(key))
      continue;
    int i = 0;
    while (i < m) {
      int idx = ((key % m) + c * i) % m;
      if (idx < 0)
        idx += m;
      if (table[idx] == -1) {
        table[idx] = key;
        used.insert(key);
        break;
      }
      ++i;
    }
  }

  for (int i = 0; i < m; ++i) {
    fout << table[i];
    if (i + 1 != m)
      fout << ' ';
  }
  fout << "\n";
  return 0;
}
