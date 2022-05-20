#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

ll init(vl &tree, vl &v, ll start, ll end, ll node) {
    if (start == end && start > 0) return tree[node] = v[start] - v[start - 1];
    ll mid = (start + end) / 2;
    return tree[node] = init(tree, v, start, mid, node * 2) + init(tree, v, mid + 1, end, node * 2 + 1);
}

void propagate(vl &tree, vl &lazy, ll start, ll end, ll node) {
    if (lazy[node] == 0) return;
    tree[node] += lazy[node] * (end - start + 1);

    if (start != end) lazy[node * 2] += lazy[node], lazy[node * 2 + 1] += lazy[node];
    lazy[node] = 0;
}

void update(vl &tree, vl &lazy, ll start, ll end, ll node, ll l, ll r, ll val) {
    propagate(tree, lazy, start, end, node);

    if (end < l || r < start) return;
    if (l <= start && end <= r) {
        lazy[node] += val;
        propagate(tree, lazy, start, end, node);
        return;
    }

    ll mid = (start + end) / 2;
    update(tree, lazy, start, mid, node * 2, l, r, val);
    update(tree, lazy, mid + 1, end, node * 2 + 1, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll getSum(vl &tree, vl &lazy, ll start, ll end, ll node, ll l, ll r) {
    propagate(tree, lazy, start, end, node);
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) / 2;
    return getSum(tree, lazy, start, mid, node * 2, l, r) + getSum(tree, lazy, mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    cin >> N;
    vl v(N + 1), tree(N * 4), lazy(N * 4);

    for (int i = 1; i <= N; ++i) cin >> v[i];
    init(tree, v, 1, N, 1);

    ll M, c1, c2, c3;
    cin >> M;

    while (M--) {
        cin >> c1 >> c2;
        if (c1 == 1) {
            cin >> c3;
            update(tree, lazy, 1, N, 1, c2, c3, 1);
            update(tree, lazy, 1, N, 1, c3 + 1, c3 + 1, c2 - c3 - 1);
        } else cout << getSum(tree, lazy, 1, N, 1, 1, c2) << "\n";
    }
}