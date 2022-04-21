#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef vector<pii> vp;

ll update(vl &tree, int start, int end, int node, int idx) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] = 1;

    int mid = (start + end) / 2;
    return tree[node] = update(tree, start, mid, node * 2, idx) + update(tree, mid + 1, end, node * 2 + 1, idx);
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

    int N;
    cin >> N;
    int treeSize = 1 << ((int) ceil(log2(N)) + 1);
    vp v(N);
    vl tree(treeSize);


    for (int i = 0; i < N; ++i) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());
    ll result{0};
    for (int i = N - 1; i >= 0; --i) {
        result += sum(tree, 0, N - 1, 1, 0, v[i].second);
        update(tree, 0, N - 1, 1, v[i].second);
    }
    cout << result << endl;
}