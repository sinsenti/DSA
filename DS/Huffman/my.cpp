#include <fstream>
#include <queue>
using namespace std;

int main() {
  ifstream fin("huffman.in");
  ofstream fout("huffman.out");
  int n;
  fin >> n;

  queue<long long> A, B;
  for (int i = 0; i < n; ++i) {
    long long freq;
    fin >> freq;
    A.push(freq);
  }

  long long total = 0;
  for (int count = 1; count < n; ++count) {
    long long f1, f2;
    if (!A.empty() && (B.empty() || A.front() <= B.front())) {
      f1 = A.front();
      A.pop();
    } else {
      f1 = B.front();
      B.pop();
    }
    if (!A.empty() && (B.empty() || A.front() <= B.front())) {
      f2 = A.front();
      A.pop();
    } else {
      f2 = B.front();
      B.pop();
    }
    long long combined = f1 + f2;
    total += combined;
    B.push(combined);
  }
  fout << total << "\n";
  return 0;
}
