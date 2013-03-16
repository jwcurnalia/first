#include <iostream>
#include <iomanip>

using namespace std;

unsigned long long int gcd(unsigned long long int a,
                           unsigned long long int b) {
  unsigned long long int r;

  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }

  return a;
}

bool isOverflow(unsigned long long int m,
                unsigned long long int n) {
  unsigned long long int i,numer,denom,d;

  numer = denom = 1;

  for (i=1;i<=m;i++) {
    numer *= n + 1 - i;
    denom *= i;

    if (numer > 0x00000000ffffffff) { // 4294967295
      return true;
    }

    d = gcd(numer,denom);

    if (d != denom)
      cout << "Wrong!\n";

    numer /= d;
    denom /= d;
  }

  return false;
}

int main(void) {
  unsigned long long int m,n,i;

  cout << " n     Overflows at m=\n"
          "---   -----------------\n";

  for (n=5;n<=100;n++) {
    cout << setw(3) << n << "    ";
    for (m=0;m<=n;m++)
      if (isOverflow(m,n))
        break;
    if (m <= n)
      cout << m << endl;
    else
      cout << "No overflow\n";
  }

  return 0;
}

