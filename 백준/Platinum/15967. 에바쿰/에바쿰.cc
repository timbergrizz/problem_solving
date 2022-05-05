#include <bits/stdc++.h>

#define ADDER(a, b, c) a += c, b += c

using namespace std;

typedef long long ll;
typedef vector<long long> vl;

ll init(vl &tree, vl &v, ll start, ll end, ll node) {
    if (start == end) return tree[node] = v[start];

    ll mid = (start + end) / 2;
    return tree[node] = init(tree, v, start, mid, node * 2) + init(tree, v, mid + 1, end, node * 2 + 1);
}

void update_lazy(vl &tree, vl &lazy, ll start, ll end, ll node) {
    if (lazy[node] == 0) return;

    tree[node] += (end - start + 1) * lazy[node];
    if (start != end) ADDER(lazy[node * 2], lazy[node * 2 + 1], lazy[node]);
    lazy[node] = 0;
}

void update(vl &tree, vl &lazy, ll start, ll end, ll node, ll l, ll r, ll c) {
    update_lazy(tree, lazy, start, end, node);
    if (end < l || r < start) return;
    if (l <= start && end <= r) {
        lazy[node] += c;
        update_lazy(tree, lazy, start, end, node);
        return;
    }

    ll mid = (start + end) / 2;
    update(tree, lazy, start, mid, node * 2, l, r, c);
    update(tree, lazy, mid + 1, end, node * 2 + 1, l, r, c);
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
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q1, q2;
    cin >> n >> q1 >> q2;
    q1 += q2;

    int treeSize = 1 << ((int) ceil(log2(n)) + 1);
    vl v(n), tree(treeSize), lazy(treeSize);

    for (ll &it: v) cin >> it;
    init(tree, v, 0, n - 1, 1);

    int c1, c2, c3, c4;
    while (q1--) {
        cin >> c1 >> c2 >> c3;
        ADDER(c2, c3, -1);
        if (c1 == 1) cout << getSum(tree, lazy, 0, n - 1, 1, c2, c3) << "\n";
        else {
            cin >> c4;
            update(tree, lazy, 0, n - 1, 1, c2, c3, c4);
        }
    }
}