#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> parentArr;
vector<int> distArr;

int find(int x) {
  int cur;
  int root = cur = x;
  int acc = 0;
  while (parentArr[root] != root) {
    acc += distArr[root];
    root = parentArr[root];
  }
  int curAcc = 0;
  while (parentArr[cur] != cur) {
    int p = parentArr[cur];
    int oldDist = distArr[cur];

    parentArr[cur] = root;
    distArr[cur] = acc - curAcc;
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

  parentArr.assign(n + 1, 0);
  distArr.assign(n + 1, 0);

  for (int i = 0; i <= n; ++i) {
    parentArr[i] = i;
    distArr[i] = 0;
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
      fout << distArr[i] << '\n';
    } else if (c == 'I') {
      int i, j;
      fin >> i >> j;
      parentArr[i] = j;
      distArr[i] = abs(i - j) % 1000;
    }
  }

  return 0;
}
