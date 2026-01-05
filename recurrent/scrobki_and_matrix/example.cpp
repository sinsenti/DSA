#include <iostream>
#include <string>
using namespace std;

void DFS(string s, int a, int b) {
  if (a == 0 && b == 0)
    cout << s << endl;
  else {
    if (a > 0)
      if (b > a)
        DFS(s + ")", a, b - 1);
    DFS(s + "(", a - 1, b);
  }
}

int main() {
  int n;
  cin >> n;
  DFS("", n, n);
  return 0;
}
