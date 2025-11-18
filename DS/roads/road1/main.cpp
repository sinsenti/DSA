#include <fstream>
#include <vector>
using namespace std;

struct DSU {
  vector<int> parent, rank;

  DSU(int n) {
    parent.resize(n + 1);
    rank.resize(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      parent[i] = i;
  }

  int find(int v) {
    if (v == parent[v])
      return v;
    return parent[v] = find(parent[v]);
  }

  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    if (rank[a] < rank[b])
      parent[a] = b;
    else {
      parent[b] = a;
      if (rank[a] == rank[b])
        rank[a]++;
    }
    return true;
  }
};

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n, q;
  fin >> n >> q;
  DSU dsu(n);
  int components = n;

  for (int i = 0; i < q; ++i) {
    int u, v;
    fin >> u >> v;
    if (dsu.unite(u, v))
      --components;
    fout << components << "\n";
  }

  fin.close();
  fout.close();
  return 0;
}
