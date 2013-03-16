#include <iostream>

using namespace std;

int main(void) {
  int a,b,tmp;

  cout << "Enter positive integers a, b: ";
  cin >> a >> b;

  if (a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }

  while (b) {
    tmp = a;
    a = b;
    b = tmp % b;
  }

  cout << "GCD is " << a << endl;

  return 0;
}
