#include <iostream>

using namespace std;

int main(void) {

int x=987654321,y=4,z=5,ans=x,tmp1=1,tmp2=1;

for (int i=0; i<4; i++)
  ans /= y;
  
for (int i=0; i<5; i++)
  ans /= z;
  
cout << ans << endl;


for (int i=0; i<4; i++)
  tmp1 *= y;
  
for (int i=0; i<5; i++)
  tmp2 *= z;
  
ans = x / (tmp1 * tmp2);

cout << ans <<endl;

return 0;
}
