#include <bits/stdc++.h>

#define FOR(i, N) for(int i=0; i < N; ++i)
using namespace std;

typedef pair<int, int> pii;
typedef vector<pii> vp;
typedef vector<int> vi;

int update(vi &tree, int start, int end, int node, int idx) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] = 1;

    int mid = (start + end) / 2;
    return tree[node] = update(tree, start, mid, node * 2, idx) + update(tree, mid + 1, end, node * 2 + 1, idx);
}

int getSum(vi &tree, int start, int end, int node, int l, int r) {
//    cout << start << end << endl;
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return getSum(tree, start, mid, node * 2, l, r) + getSum(tree, mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int treeSize = 1 << ((int) ceil(log2(N)) + 1);
    vp v(N);
    vi tree(treeSize);

    FOR(i, N) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());
    vi result(N);
    for (int i = 0; i < N; ++i) {
//        for(int i : tree) cout << i << " ";
//        cout << endl;
        result[v[i].second] = v[i].second - getSum(tree, 0, N - 1, 1, 0, v[i].second) + 1;
//        cout << v[i].first << " " << v[i].second + 1 << " " << getSum(tree, 0, N - 1, 1, 0, v[i].second);
//        cout << endl;
        update(tree, 0, N - 1, 1, v[i].second);
    }
    for(int i : result) cout << i << "\n";
}
