#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const double SQRT_5_1 = 0.4472135955,
	     PHI = 1.61803398875;

int main(void) {
  int i,a=0,b=1,f1,f2;
  ofstream outFile;

  outFile.open("output.dat");
  if (!outFile) {
    cout << "Cannot open output file\n";
    return 0;
  }

  for (i=2;i<47;i++) {
    f1 = a + b;
    a = b;
    b = f1;
    f2 = (int)(SQRT_5_1 * pow(PHI,i) + 0.5);

    outFile << f1 << "   " << f2 << endl;
  }

  outFile.close();

  return 0;
}
