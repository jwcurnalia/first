#include <iostream>
#include <cstdlib>

using namespace std;

int modExponent(int b,int e,int m) {
  int ans = 1;

  while (e != 0) {
    if (e % 2 == 1) // if (e & 1) also works
      ans = (ans * (unsigned long long int)b) % m;
    e = e / 2;
    b = (b * (unsigned long long int)b) % m;
  }

  return ans;

}

int main(int argc,char *argv[]) {
  int b,e,m,ans;

  b = atoi(argv[1]);
  e = atoi(argv[2]);
  m = atoi(argv[3]);

  ans = modExponent(b,e,m);

  cout << b << " ^ " << e << " % " << m << " = " << ans << endl;

  return 0;
}
