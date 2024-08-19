#include <iostream>
#include <vector>

using namespace std;

void merge(int B[], int iBegin, int iMiddle, int iEnd, int A[]) {
  int i = iBegin, j = iMiddle;

  for (int k = iBegin; k < iEnd; k++) {
    if (i < iMiddle && (j >= iEnd || A[i] <= A[j])) {
      B[k] = A[i];
      i = i + 1;
    } else {
      B[k] = A[j];
      j = j + 1;
    }
  }
}

void splitMerge(int B[], int iBegin, int iEnd, int A[]) {
  if (iEnd - iBegin <= 1) return;

  int iMiddle = (iEnd + iBegin) / 2;

  splitMerge(A, iBegin, iMiddle, B);
  splitMerge(A, iMiddle, iEnd, B);

  merge(B, iBegin, iMiddle, iEnd, A);
}

void mergeSort(int A[], int B[], int n) { splitMerge(A, 0, n, B); }

int main() {
  int n;
  cout << "Enter no. of elements: ";
  cin >> n;

  int A[n];
  int B[n];
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++) {
    int ele;
    cin >> ele;
    A[i] = ele;
    B[i] = ele;
  }

  mergeSort(A, B, n);

  cout << "Sorted elements are: ";
  for (int ele : A) {
    cout << ele << ' ';
  }
  cout << endl;

  return 0;
}