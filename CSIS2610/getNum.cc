#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc,char *argv[]) {
  double val;

  if (argc != 2) {
    cout << "Usage: a.out number\n";
    return 0;
  }
  val = atof(argv[1]);

  cout << "Val is " << val << endl;

  return 0;
}
