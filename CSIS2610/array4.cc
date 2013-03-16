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

int seqSearch(int data[],int n,int key) {
  int i=0;

  while (i < n && data[i] != key)
    i++;

  if (i < n) {
    cout << "Sequential probes: " << (i+1) << endl;
    return i;
  } else {
    cout << "Sequential probes: " << i << endl;
    return -1;
  }
}

int binSearch(int data[],int n,int k) {
  int low=0,high=n-1,mid,nP=0;

  while (low < high) {
    mid = (low + high) / 2;

    nP++;
    if (k > data[mid])
      low = mid + 1;
    else
      high = mid;
  }

  cout << "Binary probes: " << (nP+1) << endl;
  if (data[low] == k)
    return low;
  else
    return -1;
}

int main(void) {
  int data[30000],i,n,m;

  n = 0;
  while (n < 30000) {
    cin >> i;
    if (i <= 0)
      break;

    data[n] = i;
    n++;
  }

  for (i=n-1;i>0;i--) {
    m = findMax(data,i+1);
    swap(data[m],data[i]);
  }

  while (true) {
    cout << "Enter a number (-1 to quit): ";
    cin >> i;
    if (i == -1)
      break;
    m = binSearch(data,n,i);
    if (m > -1)
      cout << "Data found in position " << m << endl;
    else
      cout << "Data not found.\n";
    m = seqSearch(data,n,i);
    if (m > -1)
      cout << "Data found in position " << m << endl;
    else
      cout << "Data not found.\n";
  }

  return 0;
}

