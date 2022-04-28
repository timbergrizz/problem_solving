#include <bits/stdc++.h>

#define ADDER(a, b, c) a += c, b += c
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll init(vl &tree, vl &v, ll start, ll end, ll node) {
    if (start == end) return tree[node] = v[start];

    ll mid = (start + end) / 2;
    return tree[node] = init(tree, v, start, mid, node * 2) + init(tree, v, mid + 1, end, node * 2 + 1);
}

void updateLazy(vl &tree, vl &lazy, ll start, ll end, ll node) {
    if (!lazy[node]) return;

    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) ADDER(lazy[node * 2], lazy[node * 2 + 1], lazy[node]);
    lazy[node] = 0;
}

void update(vl &tree, vl &lazy, ll start, ll end, ll node, ll l, ll r, ll diff) {
    updateLazy(tree, lazy, start, end, node);
    if (end < l || r < start) return;
    if (l <= start && end <= r) {
        if (start != end) ADDER(lazy[node * 2], lazy[node * 2 + 1], diff);
        tree[node] += diff;
        return;
    }

    ll mid = (start + end) / 2;
    update(tree, lazy, start, mid, node * 2, l, r, diff);
    update(tree, lazy, mid + 1, end, node * 2 + 1, l, r, diff);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll getSum(vl &tree, vl &lazy, ll start, ll end, ll node, ll idx) {
    updateLazy(tree, lazy, start, end, node);

    if (end < idx || idx < start) return 0;
    if (start == end) return tree[node];

    ll mid = (start + end) / 2;
    return getSum(tree, lazy, start, mid, node * 2, idx) + getSum(tree, lazy, mid + 1, end, node * 2 + 1, idx);
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
//        for(ll i : tree) cout << i << " ";
//        cout << endl;

        cin >> c1;
        if (c1 == 1) {
            cin >> c2 >> c3 >> c4;
            ADDER(c2, c3, -1);
            update(tree, lazy, 0, N - 1, 1, c2, c3, c4);
        } else {
            cin >> c2;
            cout << getSum(tree, lazy, 0, N - 1, 1, c2 - 1) << "\n";
        }
    }
}