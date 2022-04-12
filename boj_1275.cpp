#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

ll update(vl &tree, int start, int end, int node, int idx, int val) {
    if (idx < start || idx > end) return tree[node];
    if (start == end) return tree[node] = val;

    int mid = (start + end) / 2;
    return tree[node] =
                   update(tree, start, mid, node * 2, idx, val) + update(tree, mid + 1, end, node * 2 + 1, idx, val);
}

ll sum(vl &tree, int start, int end, int node, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return sum(tree, start, mid, node * 2, l, r) + sum(tree, mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    int treeSize = (1 << ((int) ceil(log2(N)) + 1));
    vl tree(treeSize);

    int val;
    for (int i = 0; i < N; ++i) {
        cin >> val;
        update(tree, 0, N - 1, 1, i, val);
    }
    int c1, c2, c3, c4;
    while (Q--) {
        cin >> c1 >> c2 >> c3 >> c4;
        cout << sum(tree, 0, N - 1, 1, min(c1, c2) - 1, max(c1, c2) - 1) << "\n";
        update(tree, 0, N - 1, 1, c3 - 1, c4);
    }
}