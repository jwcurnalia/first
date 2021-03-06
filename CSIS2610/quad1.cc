#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
  double
    a,	// coefficient of x^2
    b,  // coefficient of x^1
    c,  // coefficient of x^0
    r1, // one of two roots
    r2; // the other root

  cout << "Enter a, b, c: ";
  cin >> a >> b >> c;

  r1 = (-b + sqrt(b*b-4*a*c)) / (2 * a);
  r2 = (-b - sqrt(b*b-4*a*c)) / (2 * a);

  cout << "The roots are " << r1 << " and " << r2 << endl;

  return 0;
}
