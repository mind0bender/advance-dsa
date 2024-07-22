// WAP to implement binary search w/ recursion

#include <iostream>

using namespace std;

int binarySearchWRecursion(int* arr, int n, int ele);

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

  int idx = binarySearchWRecursion(arr, n, ele);

  if (idx == -1) {
    cout << "Element not found" << endl;
  } else {
    cout << "Element found at index " << idx << endl;
  }

  cout << "Yash Gupta\t23BCS11317";

  return 0;
}

int binarySearchWRecursion(int* arr, int n, int ele) {
  if (n <= 0) {
    return -1;
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i] << '\t';
  }
  cout << endl;
  int mid = (n - 1) / 2;
  if (arr[mid] == ele) {
    return mid;
  } else if (arr[mid] < ele) {
    const int idx = binarySearchWRecursion(arr + mid + 1, n - (mid + 1), ele);
    return idx == -1 ? -1 : mid + 1 + idx;
  } else {
    return binarySearchWRecursion(arr, mid, ele);
  }
}