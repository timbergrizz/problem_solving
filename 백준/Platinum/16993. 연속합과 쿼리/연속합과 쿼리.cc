#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, N) for(int i = 1; i <= N; ++i)
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

struct maxi { ll mmax, lmax, rmax; };
typedef vector<maxi> vm;

void init(ll start, ll end, ll node, vl &v, vector<maxi> &tree) {
    if (start == end) {
        tree[node] = {v[start], v[start], v[start]};
        return;
    }

    ll lsum = 0, rsum = 0, mid = (start + end) >> 1;
    auto &lt = tree[node << 1], &rt = tree[(node << 1) + 1], &cur = tree[node];
    cur = {-INF, -INF, -INF};

    for (ll i = end; i >= start; --i) {
        lsum += v[i];
        cur.lmax = max(cur.lmax, lsum);
    }
    for (ll i = start; i <= end; ++i) {
        rsum += v[i];
        cur.rmax = max(cur.rmax, rsum);
    }

    init(start, mid, node << 1, v, tree);
    init(mid + 1, end, (node << 1) + 1, v, tree);
    cur.mmax = max({lt.mmax, rt.mmax, lt.lmax + rt.rmax});
}

maxi getMax(ll start, ll end, ll node, ll l, ll r, vm &tree, vl &cum) {
    if (end < l || r < start) return {-INF, -INF, -INF};
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) >> 1;
    maxi r1 = getMax(start, mid, node << 1, l, r, tree, cum);
    maxi r2 = getMax(mid + 1, end, (node << 1) + 1, l, r, tree,cum);
    maxi ret;

    ret.lmax = max(r1.lmax + cum[end] - cum[mid], r2.lmax);
    ret.rmax = max(r1.rmax, cum[mid] - cum[start - 1] + r2.rmax);
    ret.mmax = max({r1.mmax, r2.mmax, r1.lmax + r2.rmax});
//
//    cout << "s e :" << start << " "  << end << endl;
//    cout << ret.mmax << " " << ret.lmax << " " << ret.rmax << endl;

    return ret;
}

int main() {
    FASTIO
    int N;
    cin >> N;

    vl v(N + 1), cum(N + 1);
    vm tree(N << 2);

    FOR(i, N) {
        cin >> v[i];
        cum[i] = cum[i - 1] + v[i];
    }

    init(1, N, 1, v, tree);
    int M, c1, c2;
    cin >> M;

    while (M--) {
        cin >> c1 >> c2;
        maxi m =  getMax(1, N, 1, c1, c2, tree, cum);
        cout << m.mmax << "\n";
    }

}