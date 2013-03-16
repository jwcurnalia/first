#include <iostream>
#include <cstdlib>

using namespace std;

class lotterymachine {
private:
  int seed;
  int numbers[59];
  int powerball[39];

public:

void pick(int x){
  int n;
  srand(seed);
  for(int i=0; i<(x-1); i++){
    n=rand()%10;
    cout << n << " - ";
    }
  cout << rand()%10 << endl;
  seed = rand();
return;
}

lotterymachine() {
  seed = time(NULL);

  for(int i=0; i<59; i++)
    numbers[i] = i+1;
    
  for(int i=0; i<39; i++)
    powerball[i] = i+1;
}

void powerballgen() {
  int temp, randnum;

  for(int j=0; j<59; j++) {
  randnum = rand()%59;
  temp = numbers[j];
  numbers[j] = numbers[randnum];
  numbers[randnum] = temp;
  }
  for(int k=0; k<5; k++) {
    cout << powerball[k] << " ";
  }

  for(int j=0; j<39; j++) {
  randnum = rand()%39;
  temp = powerball[j];
  powerball[j] = powerball[randnum];
  powerball[randnum] = temp;
  }
  temp = rand()%39;
  cout << "+ " << powerball[1] << endl;
}

};

int main() {
  lotterymachine m;
  
  m.pick(3);  
  m.pick(3);
  m.pick(4);
  m.pick(4);
  m.powerballgen();
  m.powerballgen();

return 0;
}
