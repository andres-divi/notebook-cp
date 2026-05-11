map<int, int> F;

void fact(int n) {
    F.clear();
    for (int p = 2; p * p <= n; p++) {
        while (n % p == 0) {
            F[p]++;
            n /= p;
        }
    }
    if (n > 1) F[n]++;
}
