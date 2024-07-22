#include <iostream>

using namespace std;

int factorial(int);

int main() {
  int num;
  cout << "Enter a number: ";
  cin >> num;

  cout << "Factorial of " << num << " is " << factorial(num) << endl;

  cout << endl << "23BCS11317\tYash Gupta" << endl;
  return 0;
}

int factorial(int x) {
  if (!x) return 1;
  return x * factorial(x - 1);
}