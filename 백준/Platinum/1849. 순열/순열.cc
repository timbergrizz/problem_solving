#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i<= N; ++i)
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll init(vl &tree, ll start, ll end, ll node) {
    if (start == end) return tree[node] = 1;

    ll mid = (start + end) / 2;
    return tree[node] = init(tree, start, mid, node * 2) + init(tree, mid + 1, end, node * 2 + 1);
}

void query(vl &tree, vl &list, ll start, ll end, ll node, ll idx, ll k) {
    if (start == end) {
        tree[node] = 0;
        list[start] = idx;
        return;
    }

    ll mid = (start + end) / 2;
    if (k <= tree[node * 2]) query(tree, list, start, mid, node * 2, idx, k);
    else query(tree, list, mid + 1, end, node * 2 + 1, idx, k - tree[node * 2]);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vl tree(N * 4), list(N + 1), cnt(N + 1);
    init(tree, 1, N, 1);

    FOR(i, N) cin >> cnt[i];

    FOR(i, N) query(tree, list, 1, N, 1, i, cnt[i] + 1);

    FOR(i, N) cout << list[i] << "\n";

}
