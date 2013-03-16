#include <iostream>
#include <cstdlib>

using namespace std;

int extendedEuclid(int a,int b,int &x,int &y) {
  int q,r,x0,y0,tmpX,tmpY;

  x = 0;
  y = 1;
  x0 = 1;
  y0 = 0;

  while (b != 0) {
    q = a / b;
    r = a % b;

    tmpX = x0;
    tmpY = y0;

    x0 = x;
    y0 = y;

    x = tmpX - x * q;
    y = tmpY - y * q;

    a = b;
    b = r;
  }

  x = x0;
  y = y0;

  return a;
}

int main(int argc,char *argv[]) {
  int a,b,x,y,d;

  if (argc != 3) {
    cout << "Usage: " << argv[0] << " a-value b-value\n";
    return 0;
  }

  a = atoi(argv[1]);
  b = atoi(argv[2]);

  d = extendedEuclid(a,b,x,y);

  cout << a << " * " << x << " + " << b << " * " << y << " = " << d << endl;
//printf("%d * %d + %d * %d = %d\n",a,x,b,y,d);

  return 0;
}
