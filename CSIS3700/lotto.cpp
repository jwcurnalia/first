#include <iostream>
#include <cstdlib>

using namespace std;

class lotterymachine {
private:
  int seed;
  int powerball[47];

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
}

void powerballgen() {
  int temp, randnum;

  for(int i=0; i<59; i++){
    powerball[i] = i+1;
  }
  for(int j=0; j<59; j++) {
  randnum = rand()%59;
  temp = powerball[j];
  powerball[j] = powerball[randnum];
  powerball[randnum] = temp;
  }
  for(int k=0; k<5; k++) {
    cout << powerball[k] << " ";
  }
    for(int i=0; i<39; i++){
    powerball[i] = i+1;
  }
  for(int j=0; j<39; j++) {
  randnum = rand()%39;
  temp = powerball[j];
  powerball[j] = powerball[randnum];
  powerball[randnum] = temp;
  }
  temp = rand()%39;
  cout << "+ " << powerball[temp] << endl;
}

};

int main() {
  lotterymachine m;
  int selection = 0,temp;
    
while (selection != 5) {
  cout << "\033[2J\033[H";
  cout << endl;
  cout << endl;
  cout << "What game would you like a ticket for?\n";
  cout << endl;
  cout << "1. Pick 3\n";
  cout << "2. Pick 4\n";
  cout << "3. Cash 5\n";
  cout << "4. Powerball\n";
  cout << "5. Exit\n";
  cout << endl;
  cout << endl;
  cout << "Enter the number of your selection:  ";
  cin >> selection;
  cout << endl;
  cout << endl;
  
  switch(selection) {

  case 1: { 
  m.pick(3);
  }        
  break;
  case 2: { 
  m.pick(4);
  }
  break;
  case 3: { 
  m.pick(5);
  }
  break;
  case 4: {
  m.powerballgen();}
  break;
  } 
  if (selection != 5) {
    cout << endl;
    cout << endl;
    cout << "Enter '9' to continue:  ";
    cin >> temp; 
  }
}  
return 0;
}
