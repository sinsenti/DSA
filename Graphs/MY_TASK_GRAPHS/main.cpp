#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;
vector<int> dist;

int find(int x) {
  int cur;
  int root = cur = x;
  int acc = 0;
  while (parents[root] != root) {
    acc += dist[root];
    root = parents[root];
  }
  int curAcc = 0;
  while (parents[cur] != cur) {
    int p = parents[cur];
    int oldDist = dist[cur];

    parents[cur] = root;
    dist[cur] = acc - curAcc;
    curAcc += oldDist;
    cur = p;
  }
  return root;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;
  if (!(fin >> n))
    return 0;

  parents.assign(n + 1, 0);
  dist.assign(n + 1, 0);

  for (int i = 0; i <= n; ++i) {
    parents[i] = i;
    dist[i] = 0;
  }

  while (true) {
    char c;
    if (!(fin >> c))
      break;
    if (c == 'O')
      break;

    if (c == 'E') {
      int i;
      fin >> i;
      find(i);
      fout << dist[i] << '\n';
    } else if (c == 'I') {
      int i, j;
      fin >> i >> j;
      parents[i] = j;
      dist[i] = abs(i - j) % 1000;
    }
  }

  return 0;
}
