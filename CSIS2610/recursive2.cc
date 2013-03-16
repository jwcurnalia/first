#include <iostream>
#include <cstdlib>

using namespace std;

void hanoi(int nDisks,int start,int end,int temp) {

  if (nDisks > 0) {
    hanoi(nDisks-1,start,temp,end);
    cout << "Move from " << start << " to " << end << endl;
    hanoi(nDisks-1,temp,end,start);
  }
}

int main(int argc,char *argv[]) {

  hanoi(atoi(argv[1]),1,3,2);

  return 0;
}
