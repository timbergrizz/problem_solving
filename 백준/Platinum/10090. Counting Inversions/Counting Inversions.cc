#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

ll update(vl &tree, ll start, ll end, ll node, ll idx) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] += 1;

    ll mid = (start + end) / 2;
    return tree[node] = update(tree, start, mid, node * 2, idx) + update(tree, mid + 1, end, node * 2 + 1, idx);
}

ll getSum(vl &tree, ll start, ll end, ll node, ll l, ll r) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) / 2;
    return getSum(tree, start, mid, node * 2, l, r) + getSum(tree, mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<ll> tree(N * 4);

    ll result{0}, c1;
    for (int i = 1; i <= N; ++i) {
        cin >> c1;
        result += (c1 - 1 - getSum(tree, 1, N, 1, 1, c1));
        update(tree, 1, N, 1, c1);
    }
    cout << result << "\n";
}
