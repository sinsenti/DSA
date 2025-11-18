#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;

  Node(int k) : key(k), left(nullptr), right(nullptr) {};
};

class BST {
private:
  Node *root;

  void insertRecursive(Node *&node, int key) {
    if (node == nullptr) {
      node = new Node(key);
      return;
    }
    if (key < node->key) {
      insertRecursive(node->left, key);
    } else if (key > node->key) {
      insertRecursive(node->right, key);
    }
  }

  void preorderTraversal(Node *node, vector<int> &result) {
    if (node != nullptr) {
      result.push_back(node->key);
      preorderTraversal(node->left, result);
      preorderTraversal(node->right, result);
    }
  }

public:
  BST() : root(nullptr) {};
  void insert(int key) { insertRecursive(root, key); }
  vector<int> preorderTraversal() {
    vector<int> result;
    preorderTraversal(root, result);
    return result;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream f("input.txt");
  ofstream fout("output.txt");
  BST bst;
  int key;

  while (f >> key) {
    bst.insert(key);
  }
  vector<int> a = bst.preorderTraversal();
  for (int el : a) {
    fout << el << '\n';
  }

  f.close();
  fout.close();
  return 0;
}
