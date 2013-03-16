#include <iostream>

using namespace std;

int seqSearch(int data[],int n,int key) {
  int i=0;

  while (i < n && data[i] != key)
    i++;

  if (i < n)
    return i;
  else
    return -1;
}

int main(void) {
  int data[15],n,p,i;

  n = 0;
  while (n < 15) {
    cin >> i;
    if (!cin)
      break;

    data[n] = i;
    n++;
  }

  p = seqSearch(data,n,58);

  if (p >= 0)
    cout << "Found in position " << p << endl;
  else
    cout << "Not found\n";

  return 0;
}
