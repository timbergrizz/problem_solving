#include <bits/stdc++.h>

#define INF 1e9
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<vl> vvl;


void update(vvl &tree, ll k, ll value, ll start, ll end, ll node) {
    if (k < start || k > end) return;
    tree[node].push_back(value);
//    cout << value << node << endl;

    if (start == end) return;

    ll mid = (start + end) / 2;
    update(tree, k, value, start, mid, node * 2);
    update(tree, k, value, mid + 1, end, node * 2 + 1);
}

ll getCount(vvl &tree, ll start, ll end, ll node, ll v, ll l, ll r){
    if(end < l || r < start) return 0;
    if(l <= start && end <= r) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), v);

    ll mid = (start + end) / 2;
    return getCount(tree, start, mid, node * 2, v, l, r) + getCount(tree, mid + 1, end, node * 2 + 1, v, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, c1, c2, c3;
    cin >> N;

    vvl tree(400004);

    for (int i = 1; i <= N; ++i) {
        cin >> c1;
        update(tree, i, c1, 1, N, 1);
    }
    for(int i=0; i <= N * 4; ++i) sort(tree[i].begin(), tree[i].end());
//
//    for(vl it : tree)  {
//        for(ll i : it) cout << i << " ";
//        cout << endl;
//    }

    cin >> M;
    while (M--) {
        cin >> c1 >> c2 >> c3;
        cout << getCount(tree, 1, N, 1, c3, c1, c2) << "\n";
    }
}