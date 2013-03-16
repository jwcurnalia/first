#include <iostream>
#include <cstdlib>

using namespace std;

int exponent(int b,int e) {
  int ans = 1;

  while (e != 0) {
    if (e % 2 == 1) // if (e & 1) also works
      ans = ans * b;
    e = e / 2;
    b = b * b;
  }

  return ans;

}

int main(int argc,char *argv[]) {
  int b,e,ans;

  b = atoi(argv[1]);
  e = atoi(argv[2]);

  ans = exponent(b,e);

  cout << b << " ^ " << e << " = " << ans << endl;

  return 0;
}
