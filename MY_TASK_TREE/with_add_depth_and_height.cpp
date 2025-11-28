#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;
  int height;
  int depth;

  Node(int k) : key(k), left(nullptr), right(nullptr), height(0), depth(0) {}
};

Node *insert_node(Node *root, int key) {
  if (root == nullptr) {
    return new Node(key);
  }
  Node *cur = root;
  while (true) {
    if (key < cur->key) {
      if (cur->left == nullptr) {
        cur->left = new Node(key);
        break;
      } else {
        cur = cur->left;
      }
    } else {
      if (cur->right == nullptr) {
        cur->right = new Node(key);
        break;
      } else {
        cur = cur->right;
      }
    }
  }
  return root;
}

int dfs_height_depth(Node *node, int depth) {
  if (node == nullptr) {
    return 0;
  }
  node->depth = depth;
  int lh = dfs_height_depth(node->left, depth + 1);
  int rh = dfs_height_depth(node->right, depth + 1);
  node->height = (lh > rh ? lh : rh);
  return node->height + 1;
}

Node *find_min_node(Node *node) {
  while (node && node->left) {
    node = node->left;
  }
  return node;
}

Node *delete_node(Node *root, int key) {
  if (!root)
    return nullptr;
  if (key < root->key) {
    root->left = delete_node(root->left, key);
  } else if (key > root->key) {
    root->right = delete_node(root->right, key);
  } else {
    if (!root->left) {
      Node *r = root->right;
      delete root;
      return r;
    }
    if (!root->right) {
      Node *l = root->left;
      delete root;
      return l;
    }
    Node *min_node = find_min_node(root->right);
    root->key = min_node->key;
    root->right = delete_node(root->right, min_node->key);
  }
  return root;
}

void preorder_iterative(Node *root, ofstream &fout) {
  if (!root)
    return;
  stack<Node *> st;
  st.push(root);
  bool first = true;
  while (!st.empty()) {
    Node *node = st.top();
    st.pop();
    fout << node->key << '\n';
    if (node->right)
      st.push(node->right);
    if (node->left)
      st.push(node->left);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ifstream fin("in.txt");
  ofstream fout("out.txt");

  if (!fin.is_open() || !fout.is_open()) {
    return 0;
  }

  Node *root = nullptr;
  int x;
  while (fin >> x) {
    root = insert_node(root, x);
  }
  if (!root)
    return 0;

  dfs_height_depth(root, 0);

  int max_len = -1;
  Node *best_root = nullptr;

  stack<Node *> st;
  st.push(root);
  while (!st.empty()) {
    Node *node = st.top();
    st.pop();

    int left_h = node->left ? node->left->height + 1 : 0;
    int right_h = node->right ? node->right->height + 1 : 0;
    int semipath_len = left_h + right_h;

    if (semipath_len > max_len) {
      max_len = semipath_len;
      best_root = node;
    } else if (semipath_len == max_len) {
      if (!best_root || node->depth < best_root->depth) {
        best_root = node;
      }
    }

    if (node->left)
      st.push(node->left);
    if (node->right)
      st.push(node->right);
  }

  if (best_root) {
    root = delete_node(root, best_root->key);
  }

  preorder_iterative(root, fout);

  return 0;
}
