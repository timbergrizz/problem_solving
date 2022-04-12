#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

int update(vi &tree, int start, int end, int node, int idx, int val) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] = val;

    int mid = (start + end) / 2;
    return tree[node] = max(update(tree, start, mid, node * 2, idx, val),
                            update(tree, mid + 1, end, node * 2 + 1, idx, val));
}

int maxBrightness(vi &tree, int start, int end, int node, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return max(maxBrightness(tree, start, mid, node * 2, l, r), maxBrightness(tree, mid + 1, end, node * 2 + 1, l, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int treeSize = (1 << ((int)ceil(log2(N)) + 1));
    vi tree(treeSize);

    int buf;
    for (int i = 0; i < N; ++i) {
        cin >> buf;
//        cout << buf << " ";
        update(tree, 0, N - 1, 1, i, buf);
    }
//    cout << endl;

//    for(int i : tree) cout << i << " ";
//    cout << endl;

    for(int i=M - 1; i <= N - M; ++i){
        int l{i - (M - 1)}, r{ i + (M - 1)};
        cout << maxBrightness(tree, 0, N - 1, 1, l, r) << " ";
    }
    cout << "\n";
}