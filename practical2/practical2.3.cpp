// WAP to implement binary search w/ loop

#include <iostream>

using namespace std;

int binarySearchWLoop(int*, int, int);

int main() {
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];
  cout << "Enter elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ele;
  cout << "Enter element to search: ";
  cin >> ele;

  int idx = binarySearchWLoop(arr, n, ele);

  if (idx == -1) {
    cout << "element not found" << endl;
  } else {
    cout << "element found at index " << idx << endl;
  }

  cout << "Yash Gupta   23BCS11317";

  return 0;
}

int binarySearchWLoop(int* arr, int n, int ele) {
  int idx = -1;
  int l = 0, r = n - 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] == ele) {
      idx = mid;
      break;
    } else if (arr[mid] < ele) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  return idx;
}