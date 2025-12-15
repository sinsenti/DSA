#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n, m;
  fin >> n >> m;

  vector<vector<int>> adj(n + 1);

  for (int i = 0; i < m; ++i) {
    int u, v;
    fin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    fout << adj[i].size();
    for (int neighbor : adj[i]) {
      fout << " " << neighbor;
    }
    fout << "\n";
  }

  fin.close();
  fout.close();
  return 0;
}
