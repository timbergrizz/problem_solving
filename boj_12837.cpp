#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vl;

ll update(vl &tree, ll start, ll end, ll node, ll idx, ll val){
    if(idx < start || end < idx) return tree[node];
    if(start == end) return tree[node] += val;

    ll mid = (start + end) / 2;
    return tree[node] = update(tree, start, mid, node * 2, idx, val) + update(tree, mid + 1, end, node * 2 + 1, idx, val);
}

ll getSum(vl &tree, ll start, ll end, ll node, ll l, ll r){
    if(r < start || end < l) return 0;
    if(l <= start && end <= r) return tree[node];

    ll mid = (start + end) / 2;
    return getSum(tree, start, mid, node * 2, l, r) + getSum(tree, mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    int treeSize = 1 << ((int)ceil(log2(N)) + 1);
    vl tree(treeSize);

    ll c1, c2, c3;
    while(Q--){
        cin >> c1 >> c2 >> c3;
        if(c1 == 1) update(tree, 0, N - 1, 1, c2 - 1, c3);
        else cout << getSum(tree, 0, N - 1 , 1, c2 - 1, c3 - 1) << "\n";
    }
}