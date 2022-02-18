#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;

ll factorial[4000001]{1, 1, };

ll pow(ll n, ll r) {
    if (!r) return 1;
    if (r == 1) return n;

    ll p = pow(n, r / 2) % MOD;
    if(r % 2) return (((p * p) % MOD) * n) % MOD;
    return (p * p) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=1; i < 4000001; ++i) factorial[i] = (factorial[i-1] * i) % MOD;

    int T; cin >> T;
    long long N, K;
    while(T--){
        cin >> N >> K;

        ll nFac = factorial[N];
        ll kFac = factorial[K];
        kFac = (kFac * factorial[N - K]) % MOD;

        ll rev = pow(kFac, MOD - 2) % MOD;
        cout << (nFac * rev) % MOD << "\n";
    }
}