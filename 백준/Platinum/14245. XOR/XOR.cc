#include <bits/stdc++.h>

#define MID(a, b) (a + b) / 2
#define XOR(a, b, c) a ^= c, b ^= c;
#define XOR_CNT(a, b, c) for(int i=0; i < c; ++i) a ^= b;
using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll init(vl &tree, vl &v, ll start, ll end, ll node) {
    if (start == end) return tree[node] = v[start];
    ll mid = MID(start, end);
    return init(tree, v, start, mid, node * 2) ^ init(tree, v, mid + 1, end, node * 2 + 1);
}

void update_lazy(vl &tree, vl &lazy, ll start, ll end, ll node) {
    if (!lazy[node]) return;

    tree[node] ^= lazy[node] * ((end - start + 1) % 2);
    if (start != end) XOR(lazy[node * 2], lazy[node * 2 + 1], lazy[node]);
    lazy[node] = 0;
}

void update(vl &tree, vl &lazy, ll start, ll end, ll node, ll l, ll r, ll c) {
    update_lazy(tree, lazy, start, end, node);
    if (end < l || r < start) return;
    if (l <= start && end <= r) {
        tree[node] ^= c;
        if (start != end) XOR(lazy[node * 2], lazy[node * 2 + 1], c);
        return;
    }

    ll mid = MID(start, end);
    update(tree, lazy, start, mid, node * 2, l, r, c);
    update(tree, lazy, mid + 1, end, node * 2 + 1, l, r, c);
}

ll getXOR(vl &tree, vl &lazy, ll start, ll end, ll node, ll idx) {
    update_lazy(tree, lazy, start, end, node);
    if (idx < start || end < idx) return 0;
    if (start == end) return tree[node];

    ll mid = MID(start, end);
    return getXOR(tree, lazy, start, mid, node * 2, idx) ^ getXOR(tree, lazy, mid + 1, end, node * 2 + 1, idx);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int treeSize = 1 << ((int)ceil(log2(N)) + 1);
    vl v(N), tree(treeSize), lazy(treeSize);

    for(ll &i : v) cin >> i;

    init(tree, v, 0, N - 1, 1);
    ll M, c1, c2, c3, c4; cin >> M;
    while(M--){
//        for (ll i : tree) cout << i << ' ';
//        cout << endl;
        cin >> c1 >> c2;
//        cout << c1 << c2 << endl;
        if(c1 == 1) {
            cin >> c3 >> c4;
            update(tree, lazy, 0, N - 1, 1, c2, c3, c4);
        }
        else cout << getXOR(tree, lazy, 0, N - 1, 1, c2) << "\n";
    }
}