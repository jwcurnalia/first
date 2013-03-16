#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
  double
    a,	// coefficient of x^2
    b,  // coefficient of x^1
    c,  // coefficient of x^0
    d,  // discriminant
    r1, // one of two roots
    r2; // the other root

  cout << "Enter a, b, c: ";
  cin >> a >> b >> c;

  if (a == 0) {
    if (b == 0)
      cout << "Go away.\n";
    else {
      r1 = -c / b;
      cout << "The one root is " << r1 << endl;
    }
  } else {

    d = b * b - 4 * a * c;

    if (d < 0) {

      r1 = -b / (2 * a);
      r2 = sqrt(-d) / (2 * a);

      cout << "The roots are " << r1 << " + " << r2 << "i and "
           << r1 << " - " << r2 << "i\n";

    } else if (d == 0) {
      r1 = (-b + sqrt(d)) / (2 * a);

      cout << "The root is " << r1 << " with multiplicity 2\n";
    } else {

      r1 = (-b + sqrt(d)) / (2 * a);
      r2 = (-b - sqrt(d)) / (2 * a);

      cout << "The roots are " << r1 << " and " << r2 << endl;
    }
  }

  return 0;
}
