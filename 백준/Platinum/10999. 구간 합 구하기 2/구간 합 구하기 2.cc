#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll init(vl &tree, vl &v, ll start, ll end, ll node) {
    if (start == end) return tree[node] = v[start];

    ll mid = (start + end) / 2;
    return tree[node] = init(tree, v, start, mid, node * 2) + init(tree, v, mid + 1, end, node * 2 + 1);
}

void update_lazy(vl &tree, vl &lazy, ll start, ll end, ll node) {
    if (!lazy[node]) return;
//    cout << start << end << "\n";

    tree[node] += ((end - start + 1) * lazy[node]);
    if (start != end) lazy[node * 2] += lazy[node], lazy[node * 2 + 1] += lazy[node];
    lazy[node] = 0;
}

void update_range(vl &tree, vl &lazy, ll start, ll end, ll node, ll l, ll r, ll diff) {
    update_lazy(tree, lazy, start, end, node);

    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        if (start != end) lazy[node * 2] += diff, lazy[node * 2 + 1] += diff;
//        cout << (end - start + 1);
//        cout << " " << diff;
//        cout << endl;
        tree[node] += ((end - start + 1) * diff);
        return;
    }

    ll mid = (start + end) / 2;
    update_range(tree, lazy, start, mid, node * 2, l, r, diff);
    update_range(tree, lazy, mid + 1, end, node * 2 + 1, l, r, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll getSum(vl &tree, vl &lazy, ll start, ll end, ll node, ll l, ll r) {
    update_lazy(tree, lazy, start, end, node);

    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) / 2;
    return getSum(tree, lazy, start, mid, node * 2, l, r) + getSum(tree, lazy, mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int treeSize = 1 << ((int) ceil(log2(N)) + 1);
    vl tree(treeSize), lazy(treeSize);
    vl v(N);

    for (ll &i: v) cin >> i;
    init(tree, v, 0, N - 1, 1);
    ll c1, c2, c3, c4;

    FOR(i, M + K) {
//        for (ll i: tree) cout << i << " ";
//        cout << endl;
//        for (ll i: lazy) cout << i << " ";
//        cout << endl;
        cin >> c1;
        if (c1 == 1) {
            cin >> c2 >> c3 >> c4;
//            cout << c4 << endl;
            update_range(tree, lazy, 0, N - 1, 1, c2 - 1, c3 - 1, c4);
        } else {
            cin >> c2 >> c3;
            cout << getSum(tree, lazy, 0, N - 1, 1, c2 - 1, c3 - 1) << "\n";
        }
    }
}