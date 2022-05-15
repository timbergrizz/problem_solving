#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll init(vl &tree, ll start, ll end, ll node = 1) {
    if (start == end) return tree[node] = 1;

    ll mid = (start + end) / 2;
    return tree[node] = init(tree, start, mid, node * 2) + init(tree, mid + 1, end, node * 2 + 1);
}

void update(vl &tree, ll start, ll end, ll node, ll idx, ll diff) {
    if (idx < start || end < idx) return;
    tree[node] += diff;
    if (start == end) return;

    ll mid = (start + end) / 2;
    update(tree, start, mid, node * 2, idx, diff);
    update(tree, mid + 1, end, node * 2 + 1, idx, diff);
}

ll setOrder(vl &tree, ll start, ll end, ll node, ll idx, ll k) {
    if (start == end) return start;
    ll mid = (start + end) / 2, diff = tree[node * 2];

    if (diff > k) return setOrder(tree, start, mid, node * 2, idx, k);
    return setOrder(tree, mid + 1, end, node * 2 + 1, idx, k - diff);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N;
    cin >> N;
    vl tree(N * 4), list(N + 1), v(N + 1);
    init(tree, 1, N);
    FOR(i, N) cin >> v[i];

    for(ll i=N; i>0; --i) {
//        for(ll p : tree) cout << p << " ";
//        cout << endl;
        ll val = setOrder(tree, 1, N, 1, i, v[i]);
        list[val] = i;
        update(tree, 1, N, 1, val, -1);
    }

    FOR(i, N) cout << list[N - i + 1] << " ";
    cout << "\n";
}