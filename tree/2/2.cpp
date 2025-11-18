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

  Node *findMin(Node *node) {
    while (node->left != nullptr) {
      node = node->left;
    }
    return node;
  }
  Node *deleteRecursive(Node *node, int key) {
    if (node == nullptr)
      return nullptr;
    if (key < node->key) {
      node->left = deleteRecursive(node->left, key);
    } else if (key > node->key) {
      node->right = deleteRecursive(node->right, key);
    } else {
      if (node->left == nullptr) {
        Node *temp = node->right;
        delete node;
        return temp;
      } else if (node->right == nullptr) {
        Node *temp = node->left;
        delete node;
        return temp;
      } else {
        Node *temp = findMin(node->right);
        node->key = temp->key;
        node->right = deleteRecursive(node->right, temp->key);
      }
    }
    return node;
  }

public:
  BST() : root(nullptr) {};
  void insert(int key) { insertRecursive(root, key); }
  vector<int> preorderTraversal() {
    vector<int> result;
    preorderTraversal(root, result);
    return result;
  }
  void remove(int key) { root = deleteRecursive(root, key); }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ifstream f("input.txt");
  ofstream fout("output.txt");
  int toRemove;
  f >> toRemove;
  string str;
  getline(f, str);
  getline(f, str);
  BST bst;
  int key;

  while (f >> key) {
    bst.insert(key);
  }
  bst.remove(toRemove);
  vector<int> a = bst.preorderTraversal();
  for (int el : a) {
    fout << el << '\n';
  }

  f.close();
  fout.close();
  return 0;
}
