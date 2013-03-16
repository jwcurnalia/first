#include <iostream>
#include <cstdlib>

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

void decrypt(unsigned int n, unsigned int d) {
  
  unsigned int code[256] = {20481233, 52046724, 16668626, 27491596, 18737557, 18280930, 33307448};
    
  unsigned long long int i = 0, t,temp;
  
  while (i < 7) {
  
  cout << code[i] << endl;
  
  t = modExpo(code[i],d,n);
  cout << t << endl;
  
  cout << (t / 256) << endl;
  cout << (t % 256) << endl;
  cout << endl;
  
  i++;
  
  }
  cout << endl;
  
  return;
}

int main(int argc, char *argv[]) {
  unsigned int p,q,d,n,e;
  
      n = atoi(argv[2]);
      d = atoi(argv[3]);

	  decrypt(n,d);
	  
return 0;
}
