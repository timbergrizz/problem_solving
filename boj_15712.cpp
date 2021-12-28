#include <iostream>

using namespace std;

long long r, mod;

long long pow(long long n) {
    long long res{1};
    long long br{r};

    while (n) {
        if (n % 2)
            res = (res * br) % mod;
        br = (br * br) % mod;
        n /= 2;
    }
    return res % mod;
}

long long sop(long long n) {
    if (n == 1) return (r + 1) % mod;
    if (n == 0) return 1;

    long long s = sop((n - 1) / 2) % mod;

    if (n % 2) {
        long long p = pow((n + 1) / 2) % mod;
        return (((1 + p) % mod) * s) % mod;
    } else {
        return ((1 + pow(n / 2)) * s % mod + pow(n)) % mod;
    }
}

int main() {
    long long a, n;
    cin >> a >> r >> n >> mod;

    cout << (sop(n - 1 ) * a) % mod << "\n";
}