#include <iostream>

using namespace std;

int main(void) {
  float x,y;

  x = 100000000000.0;
  y = 10000000000.0;

  if (0.1 * x == y)
    cout << "equal\n";
  else
    cout << "not equal\n";

  if (0.1 * 1000000000.0 == 100000000.0)
    cout << "equal\n";
  else
    cout << "not equal\n";

  if (0.1 * 10000000000.0 == 1000000000.0)
    cout << "equal\n";
  else
    cout << "not equal\n";

  if (0.1 * 300000000000000000.0 == 30000000000000000.0)
    cout << "equal\n";
  else
    cout << "not equal\n";

  return 0;
}
