#include <string>

using namespace std;

const int N_RESIDUES = 64;

unsigned long long int findInverse(unsigned long long int,
                                   unsigned long long int);

string rnsToString (unsigned long long int[],
                    unsigned long long int[], int);

class BigNum {

  public:
    BigNum();
    ~BigNum();

    void set(unsigned int);
    void add(const BigNum &); 
    void subtract(const BigNum &); 
    void multiply(const BigNum &); 
    void divide(const BigNum &); 
    string toString(void); 

  private:
    unsigned long long int residues[N_RESIDUES];
};
