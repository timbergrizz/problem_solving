#include <bits/stdc++.h>

#define FOR(i, init, N) for(ll i=init; i< N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll result[10];

void counter(ll n, ll t) {
    while (n > 0) {
        result[n % 10] += t;
        n /= 10;
    }
}


void solve(ll A, ll B, ll t) {
    while (A % 10 && A <= B) counter(A++, t);
    if (A > B) return;

    while (B % 10 != 9 && B >= A) counter(B--, t);
    ll cnt = (B / 10 - A / 10 + 1);
    for (ll &i: result) i += cnt * t;

    solve(A / 10, B / 10, t * 10);
}

int main() {
    int n;
    cin >> n;

    solve(1, n, 1);

    for (ll i: result) cout << i << " ";
}