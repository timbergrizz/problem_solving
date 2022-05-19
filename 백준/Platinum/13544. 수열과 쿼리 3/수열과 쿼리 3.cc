#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

void update(vvl &tree, ll start, ll end, ll node, ll idx, ll val) {
    if (idx < start || end < idx) return;

    tree[node].push_back(val);
    if (start == end) return;

    ll mid = (start + end) / 2;
    update(tree, start, mid, node * 2, idx, val);
    update(tree, mid + 1, end, node * 2 + 1, idx, val);
}

ll getCount(vvl &tree, ll start, ll end, ll node, ll l, ll r, ll val) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val) ;

    ll mid = (start + end) / 2;
    return getCount(tree, start, mid, node * 2, l, r, val) + getCount(tree, mid + 1, end, node * 2 + 1, l, r, val);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    ll c1, c2, c3;
    vvl tree(N * 4);

    for (int i = 1; i <= N; ++i) {
        cin >> c1;
        update(tree, 1, N, 1, i, c1);
    }

    for (int i = 1; i < N * 4; ++i) sort(tree[i].begin(), tree[i].end());

    int M;
    cin >> M;
    ll last_ans = 0;
    while (M--) {
        cin >> c1 >> c2 >> c3;
        c1 ^= last_ans, c2 ^= last_ans, c3 ^= last_ans;
        last_ans = getCount(tree, 1, N, 1, c1, c2, c3);
        cout << last_ans << "\n";
    }
}