#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i<=N; ++i)
#define MOD 1000000007
using namespace std;

typedef long long ll;

ll v[101010];
ll tree[404040];
ll lazy[404040][2];

ll init(ll start, ll end, ll node) {
    if (start == end) return tree[node] = v[start] % MOD;

    ll mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1)) % MOD;
}

void propagate(ll start, ll end, ll node) {
    if (lazy[node][0] == 1 && lazy[node][1] == 0) return;

    ll &a1 = lazy[node][0], &b1= lazy[node][1];
    if (start != end) {
        for(ll i = node * 2; i <= node * 2 + 1; ++i) {
            ll a2 = lazy[i][0], b2 = lazy[i][1];
            lazy[i][0] = a1 * a2; lazy[i][0] %= MOD;
            lazy[i][1] = a1 * b2 + b1; lazy[i][1] %= MOD;
        }
    }

    tree[node] = tree[node] * a1 + b1 * (end - start + 1);
    tree[node] %= MOD;

    a1 = 1, b1 = 0;
}

void update(ll start, ll end, ll node, ll l, ll r, ll mul, ll sum) {
    propagate(start, end, node);
    if (end < l || r < start) return;

    if (l <= start && end <= r) {
        lazy[node][0] = (lazy[node][0] * mul) % MOD;
        lazy[node][1] = ((lazy[node][1] * mul) % MOD + sum) % MOD;
        propagate(start, end, node);
        return;
    }

    ll mid = (start + end) / 2;
    update(start, mid, node * 2, l, r, mul, sum);
    update(mid + 1, end, node * 2 + 1, l, r, mul, sum);
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

ll getResult(ll start, ll end, ll node, ll l, ll r) {
    propagate(start, end, node);
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return tree[node] % MOD;

    ll mid = (start + end) / 2;
    return getResult(start, mid, node * 2, l, r) + getResult(mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    for (int i=0; i < 101010; ++i) v[i] = 0;
    for (int i=0; i< 404040; ++i) tree[i] = 0, lazy[i][0] = 1, lazy[i][1] = 0;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    FOR(i, N) cin >> v[i];
    init(1, N, 1);

    ll M, c1, c2, c3, c4;
    cin >> M;

    while (M--) {
        cin >> c1 >> c2 >> c3;
        if (c1 != 4) cin >> c4;
        if (c1 == 1) update(1, N, 1, c2, c3, 1, c4);
        else if (c1 == 2) update(1, N, 1, c2, c3, c4, 0);
        else if (c1 == 3) update(1, N, 1, c2, c3, 0, c4);
        else cout << getResult(1, N, 1, c2, c3) % MOD << "\n";
    }
}
