#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  fstream fin("input.txt");
  ofstream fout("output.txt");

  long long n;
  fin >> n;

  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    fin >> a[i];
  }

  vector<long long> tail;

  for (long long x : a) {
    auto it = lower_bound(tail.begin(), tail.end(), x);

    if (it == tail.end()) {
      tail.push_back(x);
    } else {
      *it = x;
    }
  }

  fout << tail.size() << endl;

  fin.close();
  fout.close();
  return 0;
}
