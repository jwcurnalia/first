#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
  char str1[32],str2[32],str3[64];

  cout << "Enter two words: ";
  cin >> str1 >> str2;

//  if (str1 == str2)   <-- this does not work!
  if (strcmp(str1,str2) == 0)
    cout << "Words are equal\n";
  else
    cout << "Words are not equal\n";

//  if (str1 < str2)    <-- no!
  if (strcmp(str1,str2) < 0)
    cout << str1 << " comes before " << str2 << endl;

//  if (str1 > str2)    <-- do not use!
  if (strcmp(str1,str2) > 0)
    cout << str1 << " comes after " << str2 << endl;

  cout << "Length of first string: " << strlen(str1) << endl;

  strcpy(str3,str1);	// str3 <-- str1
  strcat(str3,str2);

  cout << "Concatenation: " << str3 << endl;

  return 0;
}
