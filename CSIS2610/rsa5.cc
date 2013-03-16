#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

bool isPrime(int n) {
  for (int j=2 ; j*j<=n ; j++)  
       if (n % j == 0)
         return false;

  return true;
}

unsigned int modExpo(unsigned int a, unsigned int b, unsigned int c) {
 int ans = 1;

 while (b != 0) {
  if (b % 2 == 1) 
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

  return a;
}

void keyGen(unsigned int p, unsigned int q, unsigned int d) {
  int x=0,y=0,e,f,g;

  f = (p-1) * (q-1);

  g = extEuclid(d,f,e,x);
  
  while(e < 0)
    e += f;

  cout << "Private Key:  " << p*q << "          d = " << d << endl;
  cout << "Public Key:   " << p*q << "          e = " << e << endl;

}

void encrypt(unsigned int n, unsigned int e) {
  string message;
  unsigned long int value;
  unsigned long int temp1,temp2; 
 
  cout << endl;
  getline(cin,message);
 
  int length = message.length();
  
  if (length % 2 == 1)
    message[length] = '\0';
	
  for (int i = 0; i < message.length(); i += 2) { 

  int j = i + 1;

  temp1 = message[i];
  
  temp2 = message[j];
  
  value = 256 * temp1 + temp2;
  
  cout << modExpo(value,e,n) << endl;
  }
  
}

void decrypt(unsigned int n, unsigned int d) {
  
  unsigned int t,temp;
  
  while (true) {

  cin >> temp;

  if (!cin)
    break;
  
  t = modExpo(temp,d,n);
  
  cout << ((char) (t / 256));
  cout << ((char) (t % 256));
  
  }

  cout << endl;

}

int main(int argc, char *argv[]) {
  unsigned int p,q,d,n,e;

  if (argv[1][0] != '-')
    goto badUsage;
 
  switch (argv[1][1])
  {
    case 'k':
      if (argc != 5)
        goto badUsage;

      p = atoi(argv[2]);
      if (isPrime(p)) 
      q = atoi(argv[3]);
      if (isPrime(q))
      d = atoi(argv[4]);
      if (isPrime(d))
      keyGen(p,q,d);

	  else
	    goto badUsage;
    break;

    case 'e':
      if (argc != 4)
        goto badUsage;

      n = atoi(argv[2]);
      e = atoi(argv[3]);

        encrypt(n,e);
		
      break;

    case 'd':
      if (argc != 4)
        goto badUsage;

      n = atoi(argv[2]);
      d = atoi(argv[3]);
 
        decrypt(n,d);

    break;

    default:
      goto badUsage;
  }

  return 0;

 badUsage: {
    cout << "-k p q d (prime)\n";
	cout << "-e n e (prime)\n";
	cout << "-d n d (prime)\n";
    return 0;}
}
