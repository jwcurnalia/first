#include <iostream>

using namespace std;

int main(void) {
  int m,n,r,a,b;

  cout << "Enter m and n: ";
  cin >> m >> n;
  cout << "GCD of " << m << " and " << n << " is ";

//  a = m;
//  b = n;

  while (n != 0) {	// this is a loop
    r = m % n;
    m = n;
    n = r;
  }

  cout << m << endl;
//  cout << "GCD of " << a << " and " << b << " is " << m << endl;
// printf("GCD of %d and %d is %d\n",m,n,m);

  return 0;
}
