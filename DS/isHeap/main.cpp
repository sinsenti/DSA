#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;

bool isHeap() {
  for (int i = 0; i < n; ++i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[i] > a[left]) {
      return false;
    }
    if (right < n && a[i] > a[right]) {
      return false;
    }
  }
  return true;
}

int main() {
  fstream fin("input.txt");
  ofstream fout("output.txt");

  fin >> n;
  int el;
  a.reserve(n);
  for (int i = 0; i < n; ++i) {
    fin >> el;
    a.push_back(el);
  }
  bool result = isHeap();
  if (result) {
    fout << "Yes\n";
  } else {
    fout << "No\n";
  }

  fin.close();
  fout.close();
  return 0;
}
