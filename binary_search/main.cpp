#include <iostream>
using namespace std;

int binarySearch(int array[], int x, int low, int high) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (x == array[mid])
      return mid;
    else if (x > array[mid])
      low = mid + 1;
    else
      high = mid - 1;
    ;
  }
  return -1;
}

int main() { return 0; }
