#include <iostream>

using namespace std;

int main(void) {
  char ch,junk;

  do {
    cout << "\033[2J\033[H"
            "Enter your choice:\n\n"
            "(\033[1;7mG\033[0m)olden Garlic\n"
            "(\033[1;7mL\033[0m)ouisiana Lickers\n"
            "(\033[1;7mA\033[0m)rizona Ranch\n"
            "(\033[1;7mP\033[0m)armesan Garlic\n"
            "(\033[1;7mK\033[0m)amikaze Garlic\n"
            "A(\033[1;7mT\033[0m)omic\n"
            "(\033[1;7mR\033[0m)anch\n"
            "Plai(\033[1;7mN\033[0m)\n"
            "\n(\033[1;7mQ\033[0m)uit\n"
            "\nEnter your choice: ";
    cin >> ch;

    switch (ch) {
     case 'G':
     case 'g':
      cout << "1 order of Golden Garlic\n";
      break;
     case 'L':
     case 'l':
      cout << "An order of Louisiana Lickers\n";
      break;
     case 'A':
     case 'a':
      cout << "Some Arizona Ranch\n";
      break;
     case 'P':
     case 'p':
      cout << "Go to BW-3 for these\n";
      break;
     case 'K':
     case 'k':
      cout << "These are at Inner Circle\n";
      break;
     case 'T':
     case 't':
      cout << "Break out the fireproof suit\n";
      break;
     case 'R':
     case 'r':
      cout << "Mild, not wild\n";
      break;
     case 'N':
     case 'n':
      cout << "Why?\n";
      break;
     case 'Q':
     case 'q':
      cout << "Quitting...\n";
      break;
     default:
      cout << "Invalid flavor " << ch << endl;
    }

// !(ch == 'Q' || ch == 'q')
//  (ch != 'Q' && ch != 'q')

    if (ch != 'Q' && ch != 'q') {
      cout << "Press . then enter:";
      cin >> junk;
    }

  } while (ch != 'Q' && ch != 'q');

  return 0;
}
