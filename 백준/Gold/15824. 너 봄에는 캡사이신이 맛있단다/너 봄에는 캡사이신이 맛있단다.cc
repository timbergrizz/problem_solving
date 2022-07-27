#include <bits/stdc++.h>

#define FOR(i, init, N) for(ll i=init; i< N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
const ll mod = 1e9 + 7;

ll power(ll n, ll p) {
    if (p <= 1) return (p ? n : 1);
    if (p % 2) return (n * power(n, p - 1) % mod) % mod;

    ll ret = (power(n, p / 2)) % mod;
    return (ret * ret) % mod;
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
        ans += v[i] * (power(2, i) + mod - power(2, (ll) N - i - 1)) % mod;
        ans %= mod;
    }

    cout << ans << "\n";
}