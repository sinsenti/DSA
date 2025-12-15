#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int n, m;
  fin >> n >> m;

  const long long INF = (long long)1e18;
  vector<vector<pair<int, int>>> g(n + 1);
  g.reserve(n + 1);

  for (int i = 0; i < m; ++i) {
    int u, v, w;
    fin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  vector<long long> dist(n + 1, INF);
  dist[1] = 0;

  using State = pair<long long, int>; // (dist, vertex)
  priority_queue<State, vector<State>, greater<State>> pq;
  pq.push({0, 1});

  while (!pq.empty()) {
    auto [d, v] = pq.top();
    pq.pop();
    if (d != dist[v])
      continue;
    if (v == n)
      break;

    for (auto [to, w] : g[v]) {
      long long nd = d + w;
      if (nd < dist[to]) {
        dist[to] = nd;
        pq.push({nd, to});
      }
    }
  }

  fout << dist[n] << '\n';
  return 0;
}
