#include <iostream>

using namespace std;

void swap(int &a,int &b) {
  int t;

  t = a;
  a = b;
  b = t;
}

int findMax(int data[],int n) {
  int i,m;

  m = 0;
  for (i=1;i<n;i++)
    if (data[i] > data[m])
      m = i;

  return m;
}

int main(void) {
  int data[15],i,n,m;

  n = 0;
  while (n < 15) {
    cin >> i;
    if (!cin)
      break;

    data[n] = i;
    n++;
  }

  cout << "Numbers:\n";

  for (i=0;i<n;i++)
    cout << data[i] << endl;

  cout << "In reverse order:\n";

  for (i=n-1;i>=0;i--)
    cout << data[i] << endl;

  m = findMax(data,n);

  cout << "Largest element: " << data[m] << " in position " << m << endl;

  for (i=n-1;i>0;i--) {
    m = findMax(data,i+1);
    swap(data[m],data[i]);
  }

  cout << "Final output:\n";

  for (i=0;i<n;i++)
    cout << data[i] << endl;

  return 0;
}

