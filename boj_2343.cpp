#include <iostream>
#include <memory.h>

using namespace std;

typedef long long ll;

ll v[100001];
ll N, M;

ll check(ll n) {
    ll sum{0}, count{1};
    for (ll i = 0; i < N; ++i) {
        sum += v[i];
        if(sum > n) i--, sum = 0, count++;
    }

    return count;
}

ll binary_search(ll l, ll r) {
    if (l == r) return l;
    if (l + 1 == r) {
        if (check(r)) return r;
        return l;
    }

    ll m = (l + r) / 2;
    if (check(m) <= M) return binary_search(l, m);
    else return binary_search(m, r);
}

int main() {
    memset(v, 0, sizeof(v));
    cin >> N >> M;

    ll maxL{0};
    for (ll i = 0; i < N; ++i) {
        cin >> v[i];
        maxL = max(maxL, v[i]);
    }
    cout << binary_search(maxL, 1000000000) << "\n";
}