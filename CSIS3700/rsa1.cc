# include <iostream>
# include <cstdlib>

using namespace std;

bool isPrime(int n) {
  for (int j=2 ; j*j<=n ; j++)   // same as j<=sqrt(i)
       if (i % j == 0)
         return false;

  return true;
}

unsigned int modExpo(unsigned int b, unsigned int e, unisgned int m) {
 int ans = 1;

 while (e != 0) {
  if (e % 2 == 1) // if (e & 1) also works
    ans = (ans * (unsigned long long int)b) % m;
  e = e / 2;
  b = (b * (unsigned long long int)b) % m;
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
  unsigned int e,x,y;

  

  e = extEuclid(p,q);

  cout << "Private Key:  " << p*q << "          d = " << d << endl;
  cout << "Public Key:  " << p*q << "          e = " << e << endl;

  return 0;
}

void encrypt(unsigned int n, unsigned int e) {
 //reads message from keyboard, encrypts, and displays output
}

void decrypt(unsigned int n, unsigned int d) {
 //Reads numbers until ^D is pressed, decrypts, and displays output

int main(int argc, char *argv[]) {
  unsigned int p,q,d,n,e;

  Bad Usage: 
    cout << "-k p q d (prime)\n"
	cout << "-e n e (prime)\n"
	cout << "-d n d (prime)\n"
  
  if (argc < 4)
    goto Bad Usage;

  if (argv[1][0] != '-')
    goto Bad Usage;
 
  switch (argv[1][1])
  {
    case k:
      if (argc != 5)
        goto Bad Usage;

      p = atoi(argv[2]);
      q = atoi(argv[3]);
      d = atoi(argv[4]);

	  if (isPrime(p) && isPrime(q) && isPrime(d))
        keyGen(p,q,d);

	  else
	    goto Bad Usage;
    break;

    case e:
      if (argc != 4)
        goto Bad Usage;

      n = atoi(argv[2]);
      e = atoi(argv[3]);

	  if (isPrime(n) && isPrime(e))
        encrypt(n,e);
		
      else
	    goto Bad Usage;

    break;

    case d:
      if (argc != 4)
        goto Bad Usage;

      n = atoi(argv[2]);
      d = atoi(argv[3]);

	  if (isPrime(n) && isPrime(d))	  
        decrypt(n,d);
		
	  else
	    goto Bad Usage;

    break;

    default:
      goto Bad Usage;
  }

  return 0;
}
