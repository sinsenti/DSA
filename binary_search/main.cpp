#include <iostream>
#include <vector>
using namespace std;

int lowerBoundBinarySearch(const vector<int> &arr, int x, int high) {
  int low = 0;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] >= x) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

int upperBoundBinarySearch(const vector<int> &arr, int x, int high) {
  int low = 0;
  while (low < high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] > x) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int k;
  cin >> k;
  vector<int> queries(k);

  for (int i = 0; i < k; i++) {
    cin >> queries[i];
  }

  for (int i = 0; i < k; i++) {
    int x = queries[i];
    int l = lowerBoundBinarySearch(arr, x, n);
    int r = upperBoundBinarySearch(arr, x, n);
    int b = (l < n && arr[l] == x) ? 1 : 0;
    cout << b << ' ' << l << ' ' << r << '\n';
  }

  return 0;
}
