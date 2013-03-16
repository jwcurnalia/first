#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(void) {
  string str1,str2;

  cout << "Enter a string: ";
  cin >> str1;

//  str2 = str1; // copy a string

  str2 = str1.substr(3,5);

  cout << "Substring: " << str2 << endl;

  cout << "Enter another string: ";
  cin >> str2;

  if (str1 == str2)
    cout << "strings are same\n";
  else if (str1 < str2)
    cout << "first string comes first\n";
  else
    cout << "second string comes first\n";

  return 0;
}
