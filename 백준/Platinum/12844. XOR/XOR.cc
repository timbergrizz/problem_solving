#include <bits/stdc++.h>

#define XOR(a, b, c) a ^= c, b ^= c
#define M(a, b) (a + b) / 2
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll init(vl &tree, vl &v, ll s, ll e, ll n) {
    if (s == e) return tree[n] = v[s];
    int m = M(s, e);
    ll fir = init(tree, v, s, m, n * 2), sec = init(tree, v, m + 1, e, n * 2 + 1);
    return tree[n] = fir ^ sec;
}

void update_lazy(vl &tree, vl &lazy, ll s, ll e, ll n) {
    if (!lazy[n]) return;

    if (s != e) XOR(lazy[n * 2], lazy[n * 2 + 1], lazy[n]);
    tree[n] ^= lazy[n] * ((e - s + 1) & 1);
    lazy[n] = 0;
}

void update(vl &tree, vl &lazy, ll s, ll e, ll n, ll l, ll r, ll c) {
    update_lazy(tree, lazy, s, e, n);

    if (e < l || r < s) return;
    if (l <= s && e <= r) {

        lazy[n] ^= c;
        update_lazy(tree, lazy, s, e, n);
        return;
    }

    ll m = M(s, e);
    update(tree, lazy, s, m, n * 2, l, r, c);
    update(tree, lazy, m + 1, e, n * 2 + 1, l, r, c);
    tree[n] = tree[n * 2] ^ tree[n * 2 + 1];

}

ll getXOR(vl &tree, vl &lazy, ll s, ll e, ll n, ll l, ll r) {
    update_lazy(tree, lazy, s, e, n);

    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return tree[n];

    ll m = M(s, e);
    return getXOR(tree, lazy, s, m, n * 2, l, r) ^ getXOR(tree, lazy, m + 1, e, n * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int treeSize = 1 << ((int) ceil(log2(N)) + 1);
    vl v(N), tree(treeSize), lazy(treeSize);

    for (ll &i: v) cin >> i;
    init(tree, v, 0, N - 1, 1);

    int M;
    cin >> M;
    ll c1, c2, c3, c4;
    while (M--) {
        cin >> c1 >> c2 >> c3;

        if (c1 == 1) {
            cin >> c4;
            update(tree, lazy, 0, N - 1, 1, c2, c3, c4);
        } else cout << getXOR(tree, lazy, 0, N - 1, 1, c2, c3) << "\n";
    }
}