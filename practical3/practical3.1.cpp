// WAP to implement binary search w/ recursion

#include <cmath>
#include <iostream>

using namespace std;

void displayComplexity(int, int, int, int);

int main() {
  int a, b, k, p;
  cout << "Enter a, b, k and p: ";
  cin >> a >> b >> k >> p;

  if (!(a >= 1) || b <= 1) {
    cerr << "Invalid input" << endl
         << "a must be greater than 0 and b must be greater than 1" << endl;
  } else {
    displayComplexity(a, b, k, p);
  }

  cout << "Yash Gupta\t23BCS11317";

  return 0;
}

void displayComplexity(int a, int b, int k, int p) {
  cout << "T(n) = " << a << "T(n/" << b << ") + (n^" << k << ")*log^" << p
       << "(n)" << endl;

  double log_b_a = log(a) / log(b);

  cout << "T(n) = Big_Theta(";

  if (log_b_a > k) {
    cout << "n^" << log_b_a;
  } else if (log_b_a == k) {
    if (p > -1) {
      cout << "(n^" << log_b_a << ")*log^" << p + 1 << "(n)";
    } else if (p == -1) {
      cout << "(n^" << log_b_a << ")*log(log(n))";
    } else {
      cout << "n^" << log_b_a;
    }
  } else if (log_b_a < k) {
    if (p >= 0) {
      cout << "(n^" << k << ")*log^" << p << "(n)";
    } else {
      cout << "n^" << k;
    }
  }
  cout << ")" << endl;
}