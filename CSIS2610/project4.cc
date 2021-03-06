#include <iostream>
#include <string>
#include "BigNum.h"

using namespace std;

int main(void) {

  BigNum answer;
  BigNum temp;
  BigNum temp2;
  BigNum divisor;
  unsigned int i,x;

  //compute 8! * 3^7 * 12! * 2^10

  answer.set(i);
  for (i=8; i>1; i--) {
  temp.set(i);
  answer.multiply(temp);
  }

  temp.set(3);
  for (i=0; i<7; i++)
    answer.multiply(temp);

  for (i=12; i>1; i--) {
  temp.set(i);
  answer.multiply(temp);
  }

  temp.set(2);
  for (i=0; i<10; i++)
    answer.multiply(temp);

  cout << "The number of permutations of a Rubix cube is "  
       << answer.toString() << endl;


  //compute 200! / (100! * 101!)

  answer.set(i);
  for (i=200; i>1; i--) {
  temp.set(i);
  answer.multiply(temp);
  }

  divisor.set(i);
  for (i=100; i>1; i--) {
  temp.set(i);
  divisor.multiply(temp);
  } 

  for (i=101; i>1; i--) {
  temp.set(i);
  divisor.multiply(temp);
  }

  answer.divide(divisor);

  cout << endl;
  cout << "The number of binary trees with 100 vertices is " 
       << answer.toString() << endl;


  //compute 52! / (13!)^4

  answer.set(i);
  for (i=52; i>1; i--) {
  temp.set(i);
  answer.multiply(temp);
  }  

  divisor.set(i);
  for (x=0; x<4; x++){
    for (i=13; i>1; i--) {
    temp.set(i);
    divisor.multiply(temp);
    } 
  }

  answer.divide(divisor);

  cout << endl;
  cout << "The number of ways a deck of cards can be " 
  cout << "dealt to four players is " 
       << answer.toString() << endl;
 
  //compute (4*(22^35)-1)/3
  
  answer.set(4);
  temp.set(22);
  for (i=0; i<35; i++)
    answer.multiply(temp);

  answer.subtract(1)
  
  answer.divide(3)
  
  cout << endl;
  cout << "The number of possible bridge auctions is " 
       << answer.toString() << endl;
	
	
  return 0;  
}
