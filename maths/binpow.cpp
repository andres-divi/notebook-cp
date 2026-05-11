//(a^b)%m
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1) // Si el bit menos significativo es 1 (b es impar)
            res = res * a % m;
        
        a = a * a % m;
        b >>= 1; // Desplaza b un bit a la derecha (equivale a b = b / 2)
    }
    return res;
}
