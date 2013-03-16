//CSIS 2617 Lab 3 - James Curnalia

#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int &a,int &b) {
  int temp;

  temp = a;
  a = b;
  b = temp;
}

int findMax(int data[],int n) {
  int i,max;

  max = 0;
  for (i=1;i<n;i++)
    if (data[i] > data[max])
      max = i;

  return max;
}

int seqSearch(int data[],int key) {
  int i=0;

  while (i < 100 && data[i] != key)
    i++;

  if (i < 100)
    return i;
  
  else 
    return 0;
}

int binSearch(int data[],int key) {
  int low=0,high=99,mid,nP=0;

  while (low < high) {
    mid = (low + high) / 2;

    nP++;
    if (key > data[mid])
      low = mid + 1;
    else
      high = mid;
  }

    if (data[low] == key)
    return (nP+1);
  else
    return 0;
}

int main(void) {
  int bindata[100],seqdata[100],i,n,m;
  float seqavg=0,binavg=0;

  int seed = time(NULL);
  srand(seed);

  for(i=0;i<100;i++) {
  bindata[i]=i;
  seqdata[i]=i;
  }

   
  for(int i=0; i<100; i++){
  int key = rand()%100;
  seqavg += seqSearch(seqdata,key);
  }

  for(int i=0; i<100; i++)
  binavg += binSearch(bindata,i);

  

  cout << "Average sequential search probes:  " << seqavg/100 << endl;
  cout << "Average binary search probes:  " << binavg/100 << endl;
  return 0;
}

