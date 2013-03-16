#include <iostream>

using namespace std;

//
// Because getRank is simple (return a basic calculation), you can also do:
//
// #define getRank(c) ((c)%13)
//

int getRank(int c) { return c % 13; }

int getSuit(int c) { return c / 13; }

bool isStraightFlush(int c1,int c2,int c3,int c4,int c5) {

  return c2 == c1 + 1 && c3 == c2 + 1 && c4 == c3 + 1 && c5 == c4 + 1;
}

bool is4Kind(int c1,int c2,int c3,int c4,int c5) {
  int r1,r2,r3,r4,r5;

  r1 = getRank(c1);
  r2 = getRank(c2);
  r3 = getRank(c3);
  r4 = getRank(c4);
  r5 = getRank(c5);

  return r2 == r3 && r3 == r4 && (r1 == r2 || r4 == r5);

//
// this is incorrect
//
//  return r2 == r3 == r4 == r5
}

bool isStraight(int c1,int c2,int c3,int c4,int c5) {
  int r1,r2,r3,r4,r5;

  r1 = getRank(c1);
  r2 = getRank(c2);
  r3 = getRank(c3);
  r4 = getRank(c4);
  r5 = getRank(c5);

  return (r2 == r1 + 1 && r3 == r2 + 1 && r4 == r3 + 1 && r5 == r4 + 1) ||
         (r1 == 0 && r2 == 1 && r3 == 2 && r4 == 3 && r5 == 12);
}

bool isFlush(int c1,int c2,int c3,int c4,int c5) {
  int s1,s2,s3,s4,s5;

  s1 = getSuit(c1);
  s2 = getSuit(c2);
  s3 = getSuit(c3);
  s4 = getSuit(c4);
  s5 = getSuit(c5);

  return s1 == s2 && s2 == s3 && s3 == s4 && s4 == s5;
}

bool is3Kind(int c1,int c2,int c3,int c4,int c5) {
  int r1,r2,r3,r4,r5;

  r1 = getRank(c1);
  r2 = getRank(c2);
  r3 = getRank(c3);
  r4 = getRank(c4);
  r5 = getRank(c5);

  return (r1 == r2 && r2 == r3) || (r2 == r3 && r3 == r4) ||
         (r3 == r4 && r4 == r5);
}

bool is2Pair(int c1,int c2,int c3,int c4,int c5) {
  int r1,r2,r3,r4,r5;

  r1 = getRank(c1);
  r2 = getRank(c2);
  r3 = getRank(c3);
  r4 = getRank(c4);
  r5 = getRank(c5);

  return (r1 == r2 && r3 == r4) || (r2 == r3 && r4 == r5) ||
         (r1 == r2 && r4 == r5);
}

bool is1Pair(int c1,int c2,int c3,int c4,int c5) {
  int r1,r2,r3,r4,r5;

  r1 = getRank(c1);
  r2 = getRank(c2);
  r3 = getRank(c3);
  r4 = getRank(c4);
  r5 = getRank(c5);

  return (r1 == r2) || (r2 == r3) || (r3 == r4) || (r4 == r5);
}

bool isFullHouse(int c1,int c2,int c3,int c4,int c5) {
  int r1,r2,r3,r4,r5;

  r1 = getRank(c1);
  r2 = getRank(c2);
  r3 = getRank(c3);
  r4 = getRank(c4);
  r5 = getRank(c5);

  return r1 == r2 && r4 == r5 && (r3 == r2 || r3 == r4);

//
// this doesn't work... give it 3 of a kind to see why
//
//  return is3Kind(c1,c2,c3,c4,c5) && is1Pair(c1,c2,c3,c4,c5);
//
}

bool isRoyalFlush(int,int,int,int,int); // prototype

bool isRoyalFlush(int c1,int c2,int c3,int c4,int c5) { // declaration

  return c5 % 13 == 12 && c2 == c1 + 1 && c3 == c2 + 1 && c4 == c3 + 1
         && c5 == c4 + 1;
//
// this is the same as...
//
//  if (c5 % 13 == 12 && c2 == c1 + 1 && c3 == c2 + 1 && c4 == c3 + 1
//         && c5 == c4 + 1)
//    return true;
//  else
//    return false;
//
}

int main(void) {
  int card1,card2,card3,card4,card5;

  cout << "Enter five cards: ";
  cin >> card1 >> card2 >> card3 >> card4 >> card5;

  if (isRoyalFlush(card1,card2,card3,card4,card5)) // function call
    cout << "Royal Flush.\n";
  else if (isStraightFlush(card1,card2,card3,card4,card5))
    cout << "Straight Flush.\n";
  else if (is4Kind(card1,card2,card3,card4,card5))
    cout << "Four of a kind.\n";
  else if (isFullHouse(card1,card2,card3,card4,card5))
    cout << "Full House.\n";
  else if (isFlush(card1,card2,card3,card4,card5))
    cout << "Flush.\n";
  else if (isStraight(card1,card2,card3,card4,card5))
    cout << "Straight.\n";
  else if (is3Kind(card1,card2,card3,card4,card5))
    cout << "Three of a kind.\n";
  else if (is2Pair(card1,card2,card3,card4,card5))
    cout << "Two pair.\n";
  else if (is1Pair(card1,card2,card3,card4,card5))
    cout << "One Pair.\n";
  else
    cout << "Nothing.\n";

  return 0;
}
