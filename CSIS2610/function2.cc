#include <iostream>

using namespace std;

void foo(void) {

  n++;
}

int main(void) {
  int n=5;

  foo();

  cout << "n = " << n << endl;
  
  return 0;
}
