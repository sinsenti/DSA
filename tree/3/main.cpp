#include <climits>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node {
  long long value;
  int left = -1;
  int right = -1;
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream fin("bst.in");
  ofstream fout("bst.out");

  int n;
  fin >> n;
  vector<Node> nodes(n);

  fin >> nodes[0].value;

  for (int i = 1; i < n; i++) {
    long long m;
    int p;
    char c;
    fin >> m >> p >> c;
    nodes[i].value = m;
    int parent_index = p - 1;
    if (c == 'L') {
      nodes[parent_index].left = i;
    } else {
      nodes[parent_index].right = i;
    }
  }

  stack<tuple<int, long long, long long>> st;
  st.push({0, LLONG_MIN, LLONG_MAX});

  while (!st.empty()) {
    auto [idx, min_val, max_val] = st.top();
    st.pop();

    long long val = nodes[idx].value;
    if (val < min_val || val > max_val) {
      fout << "NO";
      return 0;
    }

    if (nodes[idx].left != -1) {
      st.push({nodes[idx].left, min_val, val - 1});
    }
    if (nodes[idx].right != -1) {
      st.push({nodes[idx].right, val, max_val});
    }
  }

  fout << "YES";
  return 0;
}
