#include <bits/stdc++.h>

#define FOR(i, init, N) for(ll i=init; i< N; ++i)
#define MOD 1000000007
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
const ll mod = MOD;

ll power(ll n, ll p) {
    if (p <= 1) return (p ? n : 1);
    if (p % 2) return (n * power(n, p - 1) % MOD) % MOD;

    ll ret = (power(n, p / 2)) % MOD;
    return (ret * ret) % MOD;
}


int main() {
    FASTIO
    ll N;
    cin >> N;

    vl v(N);
    for (ll &i: v) cin >> i;
    sort(v.begin(), v.end());

    ll ans{0};
    FOR(i, 0, N) {
        ans = (ans + (v[i] * (power(2, i) + mod - power(2, N - i - 1)))) % mod;
//        cout << ans << endl;
    }
    cout << ans << endl;
}