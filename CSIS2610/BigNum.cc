#include "BigNum.h"

using namespace std;

static unsigned long long int moduli[64] = {
2147483647, 214748362, 2147483587, 2147483579, 2147483563, 2147483549, 2147483543, 2147483497, 
2147483489, 2147483477, 2147483423, 2147483399, 2147483353, 2147483323, 2147483269, 2147483249,
2147483237, 2147483179, 2147483171, 2147483137, 2147483123, 2147483077, 2147483069, 2147483059, 
2147483053, 2147483033, 2147483029, 2147482951, 2147482949,2147482943, 2147482937, 2147482921, 
2147482877, 2147482873, 2147482867, 2147482859, 2147482819, 2147482817, 2147482811, 2147482801, 
2147482763, 2147482739, 2147482697, 2147482693, 2147482681, 2147482663, 2147482661, 2147482621, 
2147482591, 2147482583, 2147482577, 2147482507, 2147482501, 2147482481, 2147482417, 2147482409, 
2147482367, 2147482361, 2147482349, 2147482343, 2147482327, 2147482291, 2147482273, 2147482237
};

    BigNum::BigNum(void) { 

      for (int i=0; i<N_RESIDUES; i++)
        residues[i] = 0;
    }

    BigNum::~BigNum() { }

    void BigNum::set(unsigned int v) {
      for (int i=0; i < N_RESIDUES; i++)
        residues[i] = v % moduli[i];
    };

    void BigNum::add(const BigNum &n) { 
      for (int i=0; i < N_RESIDUES; i++)
        residues[i] = (residues[i] + n.residues[i]) % moduli[i];
    };

    void BigNum::subtract(const BigNum &n) {
 
      for (int i=0; i < N_RESIDUES; i++)
        residues[i] = (residues[i] - n.residues[i]) % moduli[i];
    };

    void BigNum::multiply(const BigNum &n) { 

      for (int i=0; i < N_RESIDUES; i++)
        residues[i] = (residues[i] * n.residues[i]) % moduli[i];
    };

    void BigNum::divide(const BigNum &n) { 

      for (int i=0; i < N_RESIDUES; i++)
        residues[i] = (residues[i] * findInverse(n.residues[i], moduli[i])) % moduli[i];
    };

    string BigNum::toString(void) { 

    return rnsToString(residues,moduli,N_RESIDUES);
    };
