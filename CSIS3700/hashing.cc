#include <iostream>

using namespace std;

int hashing(int key) {
int hash;
key = key%9769;
hash = key%100;

return hash;
}

int main() {
int key,hash;
char answer='y';

while(true){
cout << "Input key to be hashed:  ";
cin  >> key;

hash = hashing(key);

cout << "Hashed Value:  " << hash << endl;

cout << "Hash another? (y/n):  ";
cin >> answer;

if(answer == 'n'||'N')
  break;
}

return 0;
}
