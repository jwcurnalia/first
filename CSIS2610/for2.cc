#include <iostream>

using namespace std;

int main(void) {
  int i,j;

  for (i=2;i<=100;i++) {

    for (j=2;j*j<=i;j++)	// same as j<=sqrt(i)
      if (i % j == 0)
        break;

    if (j * j <= i)
      continue;

    cout << i << endl;
  }

  return 0;
}
