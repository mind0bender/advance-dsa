#include <iostream>

using namespace std;

int main() {
  unsigned short n = 5;
  int arr[n];

  // Insertion
  for (int i = 0; i < n; i++) {
    cout << "Enter element " << i << ": ";
    cin >> arr[i];
  }
  cout << endl;

  // Linear Search
  int search;
  cout << "Enter Element to search: ";
  cin >> search;

  bool found = false;
  for (int i = 0; i < n; i++) {
    if (arr[i] == search) {
      cout << "Element found at index " << i << endl;
      found = true;
    }
  }
  if (!found) {
    cout << "Element not found" << endl;
  }
  cout << endl;

  // Sorting
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        arr[j] += arr[j + 1];
        arr[j + 1] = arr[j] - arr[j + 1];
        arr[j] -= arr[j + 1];
      }
    }
  }
  cout << "Sorted array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl << endl;

  // deletion
  unsigned short deleteKey;
  cout << "Enter element to delete: ";
  cin >> deleteKey;
  found = false;
  for (int i = 0; i < n; i++) {
    if (arr[i] == deleteKey) {
      found = true;
      n--;
    }
    if (found) {
      arr[i] = arr[i + 1];
    }
  }
  cout << "After deletion: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl << endl;

  return 0;
}