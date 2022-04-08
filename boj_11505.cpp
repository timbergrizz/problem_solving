#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll init(vl &v, vl &tree, int start, int end, int node) {
    if (start == end) return tree[node] = (v[start] % MOD);
    int mid = (start + end) / 2;

    return tree[node] = (init(v, tree, start, mid, node * 2) * init(v, tree, mid + 1, end, node * 2 + 1)) % MOD;
}

ll update(vl &tree, int start, int end, int node, int index, ll diff) {
    if (index < start || end < index) return tree[node];
//    cout << start << " " << end << "\n";

    if (start == end) return tree[node] = diff;

    int mid = (start + end) / 2;
    return tree[node] = (update(tree, start, mid, node * 2, index, diff) * update(tree, mid + 1, end, node * 2 + 1, index, diff)) % MOD;
}

ll mul(vl &tree, int start, int end, int node, int l, int r) {
    if (r < start || end < l) return 1;
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return (mul(tree, start, mid, node * 2, l, r) * mul(tree, mid + 1, end, node * 2 + 1, l, r)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    M += K;
    ll treeSize = (1 << ((int) ceil(log2(N)) + 1));
    vl v(N), tree(treeSize);

    for (ll &i: v) cin >> i;
    init(v, tree, 0, N - 1, 1);


    int c1, c2, c3;
    while (M--) {
//        for (ll &i: tree) cout << i << " ";
//        cout << endl;
        cin >> c1 >> c2 >> c3;
        c2 -= 1;

        if (c1 == 1) {
            v[c2] = c3;
            update(tree, 0, N - 1, 1, c2, c3);
        } else cout << mul(tree, 0, N - 1, 1, c2, c3 - 1) % MOD << "\n";
    }
}
