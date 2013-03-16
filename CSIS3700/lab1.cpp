//CSIS 3700 Lab1    Jim Curnalia

#include <iostream>

using namespace std;

class atm {
private:
float balance;
public:
void deposit(float amount) {
  balance += amount;
  return;
 }
void check_balance() {
  cout << "Current balance is " << balance << endl;
  return;
 }
void withdraw(float amount) {
  if (amount > balance)
    cout << "Withdrawl exceeds current balance.\n";
  else if (amount > 200)
    cout << "Withdrawl exceeds $200 limit.\n";
  else
    balance -= amount;
  return;
 }
atm() { balance = 0;}
};

int main(void) {

atm chase;

chase.deposit(300);
chase.withdraw(800);
chase.withdraw(250);
chase.deposit(100);
chase.withdraw(50);
chase.check_balance();

return 0;
}
