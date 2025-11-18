#include <climits>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

struct Node {
  int key;
  int left;
  int right;
  Node() : key(0), left(-1), right(-1) {}
};

vector<Node> tree;

struct StackNode {
  int index;
  long long min_val;
  long long max_val;
};

bool isBST(int root) {
  if (root == -1)
    return true;

  stack<StackNode> s;
  s.push({root, LLONG_MIN, LLONG_MAX});

  while (!s.empty()) {
    StackNode current = s.top();
    s.pop();

    int index = current.index;
    long long min_val = current.min_val;
    long long max_val = current.max_val;

    long long key = tree[index].key;

    if (key <= min_val || key >= max_val)
      return false;

    if (tree[index].right != -1) {
      s.push({tree[index].right, key, max_val});
    }
    if (tree[index].left != -1) {
      s.push({tree[index].left, min_val, key});
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  fstream fin("bst.in");
  ofstream fout("bst.out");

  std::string content((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());
  fin.close();
  std::stringstream ss(content);

  int n;
  ss >> n;

  if (n == 0) {
    cout << "YES\n";
    return 0;
  }

  tree.resize(n);

  for (int i = 0; i < n; i++) {
    tree[i].left = -1;
    tree[i].right = -1;
  }

  ss >> tree[0].key;
  int val, parent;
  char ch;
  for (int i = 1; i < n; i++) {

    ss >> val >> parent >> ch;

    tree[i].key = val;
    int index_rod = parent - 1;

    if (ch == 'L') {
      tree[index_rod].left = i;
    } else {
      tree[index_rod].right = i;
    }
  }

  bool is = isBST(0);

  if (is)
    fout << "YES\n";
  else
    fout << "NO\n";
  fout.close();

  return 0;
}
