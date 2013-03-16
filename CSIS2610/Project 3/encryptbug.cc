#include <iostream>
#include <cstdlib>
#include <string>

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

void encrypt(unsigned int n, unsigned int e) {
  string message;
  unsigned long long int value;
  unsigned long long int temp1,temp2; 
 
  cout << endl;
  getline(cin,message);
 
  int length = message.length();
  //cout << length << endl;
  if (length % 2 == 1)
    message[length] = '\0';
	
  for (int i = 0; i < message.length(); i += 2) { 

  int j = i + 1;

  temp1 = message[i];
  //cout << temp1 << endl;

  temp2 = message[j];
  //cout << temp2 << endl;

  value = 256 * temp1 + temp2;
  
  cout << modExpo(value,e,n) << endl;
  }
  
  return;
}

int main(int argc, char *argv[]) {
  unsigned int p,q,d,n,e;

      n = atoi(argv[2]);
      e = atoi(argv[3]);

        encrypt(n,e);

  return 0;
}
