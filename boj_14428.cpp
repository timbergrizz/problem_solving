#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vi;

pii u(vi &tree, int start, int end, int node, int idx, int val) {
    if (idx < start || idx > end) return tree[node];
    if (start == end) return tree[node] = {val, idx};

    int mid = (start + end) / 2;
    return tree[node] = min(u(tree, start, mid, node * 2, idx, val), u(tree, mid + 1, end, node * 2 + 1, idx, val));
}

pii m(vi &tree, int start, int end, int node, int l, int r) {
    if (r < start || end < l) return {1e9, 1e9};
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return min(m(tree, start, mid, node * 2, l, r), m(tree, mid + 1, end, node * 2 + 1, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int treeSize = 1 << ((int) (ceil(log2(N))) + 1);
    vi tree(treeSize);
    int c1, c2, c3;
    for (int i = 0; i < N; ++i) {
        cin >> c1;
        u(tree, 0, N - 1, 1, i, c1);
    }

    int M;
    cin >> M;
    while (M--) {
        cin >> c1 >> c2 >> c3;

        if (c1 == 1) u(tree, 0, N - 1, 1, c2 - 1, c3);
        else cout << m(tree, 0, N - 1, 1, min(c2, c3) - 1, max(c2, c3) - 1).second + 1<< "\n";
    }
}