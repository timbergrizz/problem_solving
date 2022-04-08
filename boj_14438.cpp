#include <bits/stdc++.h>

#define INF 1e9 + 1
using namespace std;

typedef vector<int> vi;

int init(vi &v, vi &tree, int start, int end, int node) {
    if (start == end) return tree[node] = v[start];
    int mid = (start + end) / 2;
    return tree[node] = min(init(v, tree, start, mid, node * 2), init(v, tree, mid + 1, end, node * 2 + 1));
}

void update(vi &tree, int start, int end, int node, int index, int val) {
    if(index < start || index > end) return;
    if (start == end) {
        if (start == index) tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    update(tree, start, mid, node * 2, index, val);
    update(tree, mid + 1, end, node * 2 + 1, index, val);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

int minimum(vi &tree, int start, int end, int node, int l, int r) {
    if (r < start || end < l) return INF;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;

    return min(minimum(tree, start, mid, node * 2, l, r), minimum(tree, mid + 1, end, node * 2 + 1, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int treeSize = (1 << ((int) ceil(log2(N)) + 1));
    vi v(N), tree(treeSize);
    for (int &i: v) cin >> i;
    init(v, tree, 0, N - 1, 1);

    int M;
    cin >> M;
    int o, f, s;
    while (M--) {
        cin >> o >> f >> s;
        if (o == 1) {
            f--;
            v[f] = s;
            update(tree, 0, N - 1, 1, f, s);
        }
        else cout << minimum(tree, 0, N - 1, 1, f - 1, s - 1) << "\n";
    }
}