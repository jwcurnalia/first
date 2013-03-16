#include <iostream>

using namespace std;

int main(void) {
  char name[32];
  int score;

  while (true) {
    cin.getline(name,31);

    cin >> score;
    cin.ignore(80,'\n');

    if (score == 0)
      break;

    cout << "Name: " << name << "    score: " << score << endl;
  }

  return 0;
}
