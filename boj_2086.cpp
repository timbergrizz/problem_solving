#include <iostream>
#include <vector>

#define MOD 1000000000
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> vvl;

vvl fir;

vvl produce(vvl a, vvl b) {
    vvl res(2, vector<ll>(2));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) res[i][j] += a[i][k] * b[k][j] % MOD;
        }
    }
    return res;
}

vvl dnc(ll n) {
    if (n == 1) return fir;

    vvl buf = dnc(n / 2);
    vvl res = produce(buf, buf);

    if (n % 2) return produce(res, fir);
    else return res;
}

int main() {
    for (int i = 0; i < 2; ++i)
        fir.push_back(vector<long long>(2, 1));
    fir[0][0] = 0;

    ll a, b;
    cin >> a >> b;
    vvl fb = dnc(b + 2);
    vvl fa = dnc(a + 1);
    cout << ((fb[0][1] % MOD) - (fa[0][1] % MOD) + MOD) % MOD << "\n";
}
