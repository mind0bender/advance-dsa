// sum of n natural numbers

#include <iostream>

using namespace std;

int sumOfNUntil(int);

int main() {
  int num;
  cout << "Enter a number: ";
  cin >> num;

  cout << "Sum of N natural natural numbers until " << num << " is "
       << sumOfNUntil(num) << endl;

  cout << endl << "23BCS11317\tYash Gupta" << endl;
  return 0;
}

int sumOfNUntil(int n) {
  if (!n) return 0;
  return n + sumOfNUntil(n - 1);
}