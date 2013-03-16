#include <iostream>

using namespace std;

int factorial(int n) {

  if (n == 0)
    return 1;

  return n * factorial(n-1);
}

int choose(int n,int k) {

  if (k > n)
    return 0;

  return factorial(n) / (factorial(k) * factorial(n-k));
}

int main(void) {
  int n,k,nWays;

  cout << "Enter number of items: ";
  cin >> n;
  cout << "Enter number of elements to choose: ";
  cin >> k;

  nWays = choose(n,k);

  cout << "There are " << nWays << " ways to choose " << k
       << " elements out of a set of " << n << endl;

  return 0;
}
