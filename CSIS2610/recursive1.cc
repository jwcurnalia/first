#include <iostream>

using namespace std;

int rFact(int n) {
  if (n == 0)
    return 1;
  return n * rFact(n-1);
}

int main(void) {
  int i;

  for (i=0;i<13;i++)
    cout << rFact(i) << endl;

  return 0;
}
