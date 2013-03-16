bool isPrime(int n) {

    for (int j=2;j*j<=n;j++)	// same as j<=sqrt(i)
      if (n % j == 0)
        return false;

  return true;
}
