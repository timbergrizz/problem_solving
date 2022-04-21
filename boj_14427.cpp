#include <bits/stdc++.h>

#define FOR(i, N) for(int i=0; i < N; ++i)
#define INF 1e9
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vl;

pii update(vl &tree, int start, int end, int node, int idx, int val) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] = {val, idx};

    int mid = (start + end) / 2;
    return tree[node] = min(update(tree, start, mid, node * 2, idx, val),
                            update(tree, mid + 1, end, node * 2 + 1, idx, val));
}

pii minimum(vl &tree, int start, int end, int node, int l, int r) {
    if (end < l || r < start) return {INF, INF};
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
    int treeSize = 1 << ((int) ceil(log2(N)) + 1);
    vl tree(treeSize);
    int c1, c2, c3;

    FOR(i, N) {
        cin >> c1;
        update(tree, 0, N - 1, 1, i, c1);
    }

    int M;
    cin >> M;
    while (M--) {
//        for(pii i : tree) cout << i.second << " ";
//        cout << endl;
//        for(pii i : tree) cout << i.first << " ";
//        cout << endl;

        cin >> c1;
        if (c1 == 1) {
            cin >> c2 >> c3;
            update(tree, 0, N - 1, 1, c2 - 1, c3);
        }
        else cout << tree[1].second + 1 << "\n";
    }
}