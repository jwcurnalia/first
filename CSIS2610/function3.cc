#include <iostream>

using namespace std;

//int n;

void foo(void) {
  static int n;

  cout << "In foo, n = " << n << endl;

  n = 17;

  cout << "In foo, n = " << n << endl;
}

int main(void) {

  foo();

  cout << "This is in the middle of two calls to foo()\n";

  foo();

  return 0;
}
