#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;

ll factorial(ll n) {
    long long res{1};
    while (n) res = (res * n--) % MOD;
    return res;
}


ll pow(ll n, ll p) {
    if (p == 0) return 1;
    if (p == 1) return n;
    if (p % 2) return (n * (pow(n, p - 1) % MOD)) % MOD;

    ll ret = (pow(n, p / 2)) % MOD;
    return (ret * ret) % MOD;
}

int main() {
    ll N, K;
    cin >> N >> K;

    ll nFac = factorial(N) % MOD;
    ll kFac = (factorial(K) * factorial(N - K)) % MOD;

    kFac = pow(kFac, MOD - 2);
    cout << (nFac * kFac) % MOD << "\n";
}