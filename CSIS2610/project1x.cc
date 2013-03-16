#include <iostream>

using namespace std;

char ranks[13][6]={"Two","Three","Four","Five","Six","Seven","Eight",
                     "Nine","Ten","Jack","Queen","King","Ace"};
char suits[4][9]={"Clubs","Diamonds","Hearts","Spades"};

int getRank(int c) { return c % 13; }

int getSuit(int c) { return c / 13; }

void swap(int &a,int &b) {
  int t;

  t = a;
  a = b;
  b = t;
}

int findMax(int data[],int n) {
  int i,m;

  m = 0;
  for (i=1;i<n;i++)
    if (data[i] > data[m])
      m = i;

  return m;
}

int findMaxByRank(int data[],int n) {
  int i,m;

  m = 0;
  for (i=1;i<n;i++)
    if (getRank(data[i]) > getRank(data[m]))
      m = i;

  return m;
}

void sortByRankAndSuit(int data[]) {
  int i,m;

  for (i=4;i>0;i--) {
    m = findMax(data,i+1);
    swap(data[m],data[i]);
  }
}

void sortByRank(int data[]) {
  int i,m;

  for (i=4;i>0;i--) {
    m = findMaxByRank(data,i+1);
    swap(data[m],data[i]);
  }
}

char *showRank(int c) {

  return ranks[getRank(c)];
}

char *showSuit(int c) {

  return suits[getSuit(c)];
}

void showHand(int cards[]) {

  for (int i=0;i<5;i++)
    cout << showRank(cards[i]) << " of " << showSuit(cards[i]) << endl;
}

bool isStraightFlush(int cards[]) {

  for (int i=1;i<5;i++)
    if (cards[i] != cards[i-1] + 1)
      return false;

  return true;
}

bool is4Kind(int cards[]) {

  return getRank(cards[1]) == getRank(cards[2]) &&
         getRank(cards[2]) == getRank(cards[3]) &&
         (getRank(cards[0]) == getRank(cards[1]) ||
          getRank(cards[3]) == getRank(cards[4]));

}

bool isFullHouse(int cards[]) {

  return getRank(cards[0]) == getRank(cards[1]) &&
         getRank(cards[3]) == getRank(cards[4]) &&
         (getRank(cards[2]) == getRank(cards[1]) ||
          getRank(cards[2]) == getRank(cards[3]));
}

bool isStraight(int cards[]) {

  if (getRank(cards[0]) == 0 &&
      getRank(cards[1]) == 1 &&
      getRank(cards[2]) == 2 &&
      getRank(cards[3]) == 3 &&
      getRank(cards[4]) == 12)
    return true;

  for (int i=1;i<5;i++)
    if (getRank(cards[i]) != getRank(cards[i-1]) + 1)
      return false;

  return true;
}

bool isFlush(int cards[]) {

  for (int i=1;i<5;i++)
    if (getSuit(cards[0]) != getSuit(cards[i]))
      return false;

  return true;
}

bool is3Kind(int cards[]) {
  int ranks[13]={0};

  for (int i=0;i<5;i++)
    ranks[getRank(cards[i])]++;

  for (int i=0;i<13;i++)
    if (ranks[i] == 3)
      return true;

  return false;
}

bool is2Pair(int cards[]) {
  int ranks[13]={0},n2cardPiles=0;

  for (int i=0;i<5;i++)
    ranks[getRank(cards[i])]++;

  for (int i=0;i<13;i++)
    if (ranks[i] == 2)
      n2cardPiles++;

  return n2cardPiles == 2;
}

bool is1Pair(int cards[]) {
  int ranks[13]={0};

  for (int i=0;i<5;i++)
    ranks[getRank(cards[i])]++;

  for (int i=0;i<13;i++)
    if (ranks[i] == 2)
      return true;

  return false;
}

bool isRoyalFlush(int cards[]) {

  return getRank(cards[4]) == 12 && isStraightFlush(cards);
}

int main(void) {
  int cards[5];

  cout << "Enter five cards: ";
  for (int i=0;i<5;i++)
    cin >> cards[i];

  sortByRankAndSuit(cards);

  showHand(cards);

  sortByRank(cards);

  if (isRoyalFlush(cards)) // function call
    cout << "Royal Flush.\n";
  else if (isStraightFlush(cards))
    cout << "Straight Flush.\n";
  else if (is4Kind(cards))
    cout << "Four of a kind.\n";
  else if (isFullHouse(cards))
    cout << "Full House.\n";
  else if (isFlush(cards))
    cout << "Flush.\n";
  else if (isStraight(cards))
    cout << "Straight.\n";
  else if (is3Kind(cards))
    cout << "Three of a kind.\n";
  else if (is2Pair(cards))
    cout << "Two pair.\n";
  else if (is1Pair(cards))
    cout << "One Pair.\n";
  else
    cout << "Nothing.\n";

  return 0;
}
