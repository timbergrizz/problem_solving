#include <bits/stdc++.h>

#define FOR(i, N) for(int i = 1; i <= N; ++i)
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

void update(vvl &tree, ll start, ll end, ll node, ll idx, ll val) {
    if (idx < start || end < idx) return;

    tree[node].push_back(val);
    ll mid = (start + end) >> 1;

    if (start == end) return;
    update(tree, start, mid, node * 2, idx, val);
    update(tree, mid + 1, end, node * 2 + 1, idx, val);
}

ll getOrder(vvl &tree, ll start, ll end, ll node, ll l, ll r, ll val) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return upper_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();

    ll mid = (start + end) >> 1;
    return getOrder(tree, start, mid, node * 2, l, r, val) + getOrder(tree, mid + 1, end, node * 2 + 1, l, r, val);
}

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL);
    cout.tie(NULL);

    ll N, M;
    cin >> N >> M;
    vvl tree(N * 4);

    ll c1, c2, c3;
    FOR(i, N) {
        cin >> c1;
        update(tree, 1, N, 1, i, c1);
    }
    FOR(i, N * 4 - 1) sort(tree[i].begin(), tree[i].end());
    FOR(i, M){
        cin >> c1 >> c2 >> c3;
        ll l = -1e9, r = 1e9, mid;
        while (l <= r){
            mid = (l + r) >> 1;
            ll order = getOrder(tree, 1, N, 1, c1, c2, mid);
            if(order < c3) l = mid + 1;
            else r = mid - 1;
        }

        cout << l << "\n";
    }

}