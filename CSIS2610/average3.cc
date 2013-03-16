#include <iostream>

using namespace std;

int main(void) {
  int grade,sum=0,count=0;

  while (true) {
    cout << "Enter a grade (-1 to quit): ";
    cin >> grade;

    if (grade < 0)
      break;

    sum += grade;
    count++;
  }

  cout << "Average: " << sum / (double)count << endl;

  return 0;
}
