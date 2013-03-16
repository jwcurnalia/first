#include <iostream>

using namespace std;

int main(void) {
  int x,data[]={1,1,2,6,24,120,720,5040,40320,362880,3628800};
  int *px,*pData;

  pData = new int[10];
  pData[5] = 0;
  delete pData;

  x = 17;

  px = &x;

  cout << "X is " << *px << endl;

  *px = -5;

  cout << "X is " << *px << endl;

  cout << "data are " << data << endl;

  pData = data;
  //data = pData; // illegal

  cout << "6! = " << pData[6] << endl;

  pData = data + 3;

  cout << "6! = " << pData[6] << endl;

  return 0;
}
