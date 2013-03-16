#include <iostream>
#include <string>

using namespace std;

struct Person {
  string name;
  int left,right;
};

Person people[10];

int insert(int r,int n) {

  if (r == -1)
    return n;

  if (people[n].name > people[r].name)
    people[r].right = insert(people[r].right,n);
  else
    people[r].left = insert(people[r].left,n);

  return r;
}

void inOrder(int r) {

  if (r != -1) {
    inOrder(people[r].left);

    cout << people[r].name << endl;

    inOrder(people[r].right);
  }
}

int main(void) {
  int nPeople=0,root=-1;

  while (true) {
    cout << "enter a person: ";
    cin >> people[nPeople].name;

    if (!cin)
      break;

    people[nPeople].left = -1;
    people[nPeople].right = -1;

    root = insert(root,nPeople);

    nPeople++;
  }

  cout << "\n\n";

  inOrder(0);

  return 0;
}
