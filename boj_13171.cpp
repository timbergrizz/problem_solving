#include <iostream>

using namespace std;

#define MOD 1000000007
typedef unsigned long long ull;

int main() {
    ull x, n;
    cin >> x >> n;
    x %= MOD;

    ull ans = 1;

    while (n) {
        if (n % 2) ans = (ans * x) % MOD;
        x = (x * x) % MOD, n >>= 1;
    }

    cout << ans << '\n';
}