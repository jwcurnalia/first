# include <iostream>
# include <cstdlib>

using namespace std;

bool isPrime(int n) {
  for (int j=2 ; j*j<=n ; j++)   // same as j<=sqrt(i)
       if (n % j == 0)
         return false;

  return true;
}

unsigned int modExpo(unsigned int a, unsigned int b, unsigned int c) {
 int ans = 1;

 while (b != 0) {
  if (b % 2 == 1) // if (b & 1) also works
    ans = (ans * (unsigned long long int)a) % c;
  b = b / 2;
  a = (a * (unsigned long long int)a) % c;
  }

 return ans;
}

int extEuclid(int a, int b, int &x, int &y) {
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

  return y;
}

void keyGen(unsigned int p, unsigned int q, unsigned int d) {
  int x=0,y=0;

  cout << "Private Key:  " << p*q << "          d = " << d << endl;
  cout << "Public Key:   " << p*q << "          e = " << extEuclid(p,q,x,y) 
  << endl;

  return;
}

int main(int argc, char *argv[]) {
  unsigned int p,q,d,n,e;

      p = atoi(argv[2]);
      if (isPrime(p)) 
      q = atoi(argv[3]);
      if (isPrime(q))
      d = atoi(argv[4]);
      if (isPrime(d))
      keyGen(p,q,d);

  return 0;
}

