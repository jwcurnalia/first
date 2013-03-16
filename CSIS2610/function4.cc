#include <iostream>

using namespace std;

void foo(int n) {

  n++;

  cout << "In foo, n = " << n << endl;
}

int main(void) {
  int n=5;

  foo(n);

  cout << "In main, n = " << n << endl;
  
  return 0;
}
