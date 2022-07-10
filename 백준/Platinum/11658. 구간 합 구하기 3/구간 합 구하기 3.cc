#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppl;
typedef vector<ll> vl;
typedef vector<vl> vvl;

using namespace std;

vvl tree;
ll v[1025][1025];
int h = 1;

void update(ll x1, ll y1, ll d) {
    ll i = y1 + h - 1, j = x1 + h - 1;
    tree[i][j] = d;

    while (j > 1) {
        j >>= 1;
        tree[i][j] = tree[i][j << 1] + tree[i][(j << 1) + 1];
    }
    while (i > 1) {
        j = x1 + h - 1, i >>= 1;
        tree[i][j] = tree[i << 1][j] + tree[(i << 1) + 1][j];
        while (j > 1) {
            j >>= 1;
            tree[i][j] = tree[i][j << 1] + tree[i][(j << 1) + 1];
        }
    }
}

ll xSum(ll nodey, ll s, ll e, ll node, ll l, ll r) {
//    cout << "   " << s << e << endl;
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return tree[nodey][node];

    ll mid = (s + e) >> 1;
    ll left = xSum(nodey, s, mid, (node << 1), l, r), right = xSum(nodey, mid + 1, e, (node << 1) + 1, l, r);
//    cout << "    " << left << right << endl;
    return left + right;
}

ll ySum(ll s, ll e, ll node, ll l, ll r, ll xl, ll xr) {
//    cout << s << " " << e << endl;
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return xSum(node, 1, h, 1, xl, xr);

    ll mid = (s + e) >> 1;
    ll left = ySum(s, mid, node << 1, l, r, xl, xr);
    ll right = ySum(mid + 1, e, (node << 1) + 1, l, r, xl, xr);
//    cout << left << right << endl;
    return left + right;
}

int main() {
    FASTIO;
    ll N, M;
    cin >> N >> M;
    while (h < N) h <<= 1;

    tree = vvl(h * 2, vl(h * 2));

    FOR(i, N) FOR(j, N) {
            cin >> v[i][j];
            update(i, j, v[i][j]);
        }

    int c1, c2, c3, c4, c5;
    FOR(i, M) {
        cin >> c1 >> c2 >> c3 >> c4;
        if (c1) {
            cin >> c5;
            if (c2 > c4) swap(c2, c4);
            if (c3 > c5) swap(c3, c5);
            cout << ySum(1, h, 1, c3, c5, c2, c4) << "\n";
        } else update(c2, c3, c4);
//
//        for(auto it : tree){
//            for(auto i : it) cout << i << " ";
//            cout << endl;
//        }
    }
}