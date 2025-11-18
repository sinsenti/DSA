#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct DSU {
  vector<int> parent, size;
  int cnt;
  DSU(int n) : parent(n), size(n, 1), cnt(n) {
    for (int i = 0; i < n; ++i)
      parent[i] = i;
  }
  int find(int x) {
    if (parent[x] != x)
      parent[x] = find(parent[x]);
    return parent[x];
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (size[x] < size[y])
      swap(x, y);
    parent[y] = x;
    size[x] += size[y];
    --cnt;
  }
  bool connected() const { return cnt == 1; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n, m, q;
  fin >> n >> m >> q;
  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    fin >> u >> v;
    --u;
    --v;
    edges[i] = {u, v};
  }
  vector<int> queries(q);
  set<int> removed;
  for (int i = 0; i < q; ++i) {
    fin >> queries[i];
    --queries[i];
    removed.insert(queries[i]);
  }

  DSU dsu(n);
  for (int i = 0; i < m; ++i) {
    if (!removed.count(i)) {
      dsu.unite(edges[i].first, edges[i].second);
    }
  }

  vector<char> res(q);
  for (int i = q - 1; i >= 0; --i) {
    res[i] = dsu.connected() ? '1' : '0';
    int id = queries[i];
    dsu.unite(edges[id].first, edges[id].second);
  }

  for (char c : res)
    fout << c;
  fout << '\n';

  fin.close();
  fout.close();
  return 0;
}
