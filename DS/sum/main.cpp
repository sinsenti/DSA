#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct SegmentTree {
  int n;
  vector<long long> tree;

  SegmentTree(const vector<long long> &a) {
    n = a.size();
    tree.assign(2 * n, 0);
    for (int i = 0; i < n; ++i)
      tree[n + i] = a[i];
    for (int i = n - 1; i > 0; --i)
      tree[i] = tree[2 * i] + tree[2 * i + 1];
  }

  void add(int i, long long x) {
    i = i + n;
    tree[i] += x;
    while (i > 1) {
      i = i / 2;
      tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
  }

  long long query(int l, int r) const {
    long long res = 0;
    l = l + n;
    r = r + n;
    while (l < r) {
      if (l % 2 == 1) {
        res += tree[l];
        l = l + 1;
      }
      if (r % 2 == 1) {
        r = r - 1;
        res += tree[r];
      }
      l = l / 2;
      r = r / 2;
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  SegmentTree st(a);

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    string type;
    cin >> type;
    if (type == "Add") {
      int i;
      long long x;
      cin >> i >> x;
      st.add(i, x);
    } else if (type == "FindSum") {
      int l, r;
      cin >> l >> r;
      cout << st.query(l, r) << '\n';
    }
  }
  return 0;
}
