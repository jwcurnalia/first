#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void loadData(string names[],string colors[],int &n) {
  ifstream inFile;
  int i;

  inFile.open("colors.dat");
  if (!inFile)
    return;

  inFile >> n;
  for (i=0;i<n;i++)
    inFile >> names[i] >> colors[i];

  inFile.close();
}

void saveData(string names[],string colors[],int n) {
  ofstream outFile;
  int i;

  outFile.open("colors.dat");
  if (!outFile)
    return;

  outFile << n << endl;
  for (i=0;i<n;i++)
    outFile << names[i] << ' ' << colors[i] << endl;

  outFile.close();
}

int main(void) {
  string names[32],colors[32],name;
  int i,nNames=0;
  char ch;

  loadData(names,colors,nNames);

  do {
    cout << "Menu:\n\n"
            "(a)dd name\n"
	    "(r)emove name\n"
	    "(m)odify color\n"
	    "(d)isplay colors\n\n"
            "(q)uit\n\n"
	    "Enter your choice: ";
    cin >> ch;
    if (ch == 'a' || ch == 'A') {
      cout << "Enter name: ";
      cin >> names[nNames];
      cout << "Enter favorite color: ";
      cin >> colors[nNames];
      nNames++;
    } else if (ch == 'r' || ch == 'R') {
      cout << "Enter name to be removed: ";
      cin >> name;
      for (i=0;i<nNames;i++)
        if (name == names[i])
          break;
      if (i == nNames)
        cout << "Name not found\n";
      else {
        nNames--;
        names[i] = names[nNames];
        colors[i] = colors[nNames];
      }
    } else if (ch == 'm' || ch == 'M') {
      cout << "Enter name to be modified: ";
      cin >> name;
      for (i=0;i<nNames;i++)
        if (name == names[i])
          break;
      if (i == nNames)
        cout << "Name not found\n";
      else {
        cout << "Enter new color: ";
        cin >> colors[i];
      }
    } else if (ch == 'd' || ch == 'D') {
      for (i=0;i<nNames;i++)
        cout << names[i] << " likes " << colors[i] << endl;
    } else if (ch == 'q' || ch == 'Q') {
      break;
    } else {
      cout << "Invalid command.\n";
    }
  } while (true);

  saveData(names,colors,nNames);

  return 0;
}
