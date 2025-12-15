#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  fstream fin("input.txt");
  ofstream fout("output.txt");
  int n;
  fin >> n;
  int a, b;
  vector<int> parent(n + 1, 0);
  for (int i = 0; i <= n - 1; i++) {
    fin >> a >> b;
    parent[b] = a;
  }
  for (int i = 1; i <= n; i++) {
    fout << parent[i] << ' ';
  }
  fin.close();
  fout.close();
}
