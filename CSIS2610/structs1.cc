#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Bowler {
  string name;
  int scores[3];
  double avg;
};

Bowler team[4];

void getTeam(ifstream &f,Bowler team[]) {

  for (int i=0;i<4;i++) {
    f >> team[i].name;
    for (int j=0;j<3;j++)
      f >> team[i].scores[j];
  }
}

void doAverages(Bowler team[]) {
  int sum;

  for (int i=0;i<4;i++) {
    sum = 0;
    for (int j=0;j<3;j++)
      sum += team[i].scores[j];
    team[i].avg = sum / 3.0;
  }
}

int main(void) {
  ifstream inFile;

  inFile.open("bowling.dat");
  if (!inFile) {
    cerr << "Error opening bowling.dat\n";
    return 0;
  }

  getTeam(inFile,team);

  inFile.close();

  doAverages(team);

  for (int i=0;i<4;i++)
    cout << team[i].name << "  " << team[i].avg << endl;

  return 0;
}
