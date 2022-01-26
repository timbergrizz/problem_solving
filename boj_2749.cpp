#include <iostream>
#include <vector>

#define MOD 1000000
using namespace std;

typedef vector<vector<long long>> vvi;
typedef vector<long long> vi;
typedef long long ll;

vvi base;

vvi prod(const vvi &a, const vvi &b) {
    vvi ret(2, vi(2, 0));

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) ret[i][j] = (ret[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
        }
    }
    return ret;
}

vvi fib(ll n) {
    if(n == 1) return base;

    vvi buf = fib(n / 2);
    if (n % 2) return prod(prod(buf, buf), base);
    else return prod(buf, buf);
}

int main() {
    base = vvi(2, vi(2, 1));
    base[0][0] = 0;

    ll N;
    cin >> N;

    vvi res = fib(N);
    cout << res[0][1] << "\n";
}