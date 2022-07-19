#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define INF 251
#define FOR(i, init, n) for(int i=init; i < n; ++i)

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll N, B, K;
vvl min_tree, max_tree;

void init() {
    min_tree = vvl(N + 10, vl(N * 4 + 10, 1e9));
    max_tree = vvl(N + 10, vl(N * 4 + 10));
}

ll min_update(ll y, ll x, ll val, ll node = 1, ll start = 1, ll end = N) {
    if (end < x || x < start) return min_tree[y][node];
    if (start == end) return min_tree[y][node] = val;

    ll mid = (start + end) >> 1, lnode = node << 1, rnode = node << 1 | 1;
    return min_tree[y][node] = min(min_update(y, x, val, lnode, start, mid),
                                   min_update(y, x, val, rnode, mid + 1, end));
}

ll max_update(ll y, ll x, ll val, ll node = 1, ll start = 1, ll end = N) {
    if (end < x || x < start) return max_tree[y][node];
    if (start == end) return max_tree[y][node] = val;

    ll mid = (start + end) >> 1, lnode = node << 1, rnode = node << 1 | 1;
    return max_tree[y][node] = max(max_update(y, x, val, lnode, start, mid),
                                   max_update(y, x, val, rnode, mid + 1, end));
}

ll get_min(ll y, ll xl, ll xr, ll node = 1, ll start = 1, ll end = N) {
    if (end < xl || xr < start) return 1e9;
    if (xl <= start && end <= xr) return min_tree[y][node];

    ll mid = (start + end) >> 1, lnode = node << 1, rnode = node << 1 | 1;
    return min(get_min(y, xl, xr, lnode, start, mid),
               get_min(y, xl, xr, rnode, mid + 1, end));
}

ll get_max(ll y, ll xl, ll xr, ll node = 1, ll start = 1, ll end = N) {
    if (end < xl || xr < start) return 0;
    if (xl <= start && end <= xr) return max_tree[y][node];

    ll mid = (start + end) >> 1, lnode = node << 1, rnode = node << 1 | 1;
    return max(get_max(y, xl, xr, lnode, start, mid),
               get_max(y, xl, xr, rnode, mid + 1, end));
}

ll get_val(int y, int x) {
    ll min_val = 1e9, max_val = 0;
    FOR(i, y, y + B) {
        min_val = min(min_val, get_min(i, x, x + B - 1));
        max_val = max(max_val, get_max(i, x, x + B - 1));
    }
//    cout << min_val << " " << max_val << "\n";
    return max_val - min_val;
}

int main() {
    FASTIO
    cin >> N >> B >> K;
    ll c1, c2;
    init();

    FOR(i, 1, N + 1) {
        FOR(j, 1, N + 1) {
            cin >> c1;
            min_update(i, j, c1);
            max_update(i, j, c1);
        }
    }
//
//    FOR(i, 1, N){
//        FOR(j, 1, N * 4)  cout << min_tree[i][j] << " ";
//        cout << endl;
//    }
//    FOR(i, 1, N){
//        FOR(j, 1, N * 4)  cout << max_tree[i][j] << " ";
//        cout << endl;
//    }

    while (K--) {
        cin >> c1 >> c2;
        cout << get_val(c1, c2) << "\n";
    }
}
