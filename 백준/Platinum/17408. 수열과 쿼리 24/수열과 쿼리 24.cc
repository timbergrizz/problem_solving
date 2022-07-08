#include <bits/stdc++.h>

#define INF 101010
#define FOR(i, n) for(ll i=1; i<=n; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll v[INF], N;
pll tree[INF * 4];

void init() {
    memset(v, 0, sizeof v);
    memset(tree, 0, sizeof tree);
}

pll tree_build(ll n, ll s, ll e) {
    if (s == e) return tree[n] = {v[s], s};

    ll mid = (s + e) >> 1;
    pll left = tree_build(n << 1, s, mid);
    pll right = tree_build((n << 1) + 1, mid + 1, e);

    return tree[n] = max(left, right);
}

pll update(ll n, ll s, ll e, ll idx, ll val) {
    if (idx < s || e < idx) return tree[n];
    if (s == e) return tree[n] = {val, idx};

    ll mid = (s + e) >> 1;
    pll left = update(n << 1, s, mid, idx, val);
    pll right = update((n << 1) + 1, mid + 1, e, idx, val);

    return tree[n] = max(left, right);
}

pll get_max(ll n, ll s, ll e, ll l, ll r) {
    if (e < l || r < s) return {0, 0};
    if (l <= s && e <= r) return tree[n];

    ll mid = (s + e) >> 1;
    pll left = get_max(n << 1, s, mid, l, r);
    pll right = get_max((n << 1) + 1, mid + 1, e, l, r);

    return max(left, right);
}

ll get_max_sum(int l, int r){
    pll m = get_max(1, 1, N, l, r);

    ll second{0};
    if(m.second - 1 >= l) second = max(second, get_max(1, 1, N, l, m.second - 1).first);
    if(m.second + 1 <= r) second = max(second, get_max(1, 1, N, m.second + 1, r).first);

    return m.first + second;
}


int main() {
    FASTIO
    init();
    int M, c1, c2, c3;
    cin >> N;
    FOR(i, N) cin >> v[i];
    tree_build(1, 1, N);

    cin >> M;

    while (M--) {
        cin >> c1 >> c2 >> c3;

        if(c1 == 2) cout << get_max_sum(c2, c3) << "\n";
        else {
            v[c2] = c3;
            update(1, 1, N, c2, c3);
        }
    }
}