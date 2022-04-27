#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<pii> vp;
typedef vector<ll> vi;

ll update(vi &tree, int start, int end, int node, int idx) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] += 1;

    int mid = (start + end) / 2;
    return tree[node] = update(tree, start, mid, node * 2, idx) + update(tree, mid + 1, end, node * 2 + 1, idx);
}

ll sum(vi &tree, int start, int end, int node, int l, int r) {
//    cout << start << " " << end << " " << l << ' ' << r << endl;
    if(end < l || r < start) return 0;
    if(l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return sum(tree, start, mid, node * 2, l, r) + sum(tree, mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int treeSize = 1 << ((int) ceil(log2(N)) + 1);
    vi tree(treeSize);
    vp v(K);

    for (pii &it: v) cin >> it.first >> it.second;
    sort(v.begin(), v.end());

    ll result{0};
    for (pii it: v) {
        if(it.second < N) result += sum(tree, 1, N, 1, it.second + 1, N);
        update(tree, 1, N, 1, it.second);
//        cout << result << endl;
    }
    cout << result << "\n";
}