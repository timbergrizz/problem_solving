#include <bits/stdc++.h>

#define FOR(i, init, N) for(int i=init; i<= N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<ll> vi;

ll kmp(string &P, ll m) {
    vi f(m + 1);
    ll cnt{0};
    FOR(i, 1, m - 1) {
        while (cnt > 0 && P[i] != P[cnt]) cnt = f[cnt - 1];
        if (P[i] == P[cnt]) f[i] = ++cnt;
    }
    return f[m - 1];
}

int main() {
    ll N;
    string P;
    cin >> P >> N;
    ll len = (ll)P.length();

    cout << (N - 1) * (len - kmp(P, len)) + len;
}