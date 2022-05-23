#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;

ll init(ll start, ll end, ll node, vl &tree, vl &v){
    if(start == end) return tree[node] = v[start];

    ll mid = (start + end) >> 1;
    return tree[node] = min(init(start, mid, node * 2, tree, v), init(mid + 1, end, node * 2 + 1, tree, v));
}

ll getMin(ll start, ll end, ll node, ll l, ll r, vl &tree){
    if(end < l || r < start) return 1e9;
    if(l <= start && end <= r) return tree[node];

    ll mid = (start + end) >> 1;
    return min(getMin(start, mid, node * 2, l, r, tree), getMin(mid + 1, end, node * 2 + 1, l, r, tree));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vl v(N + 1), tree(N * 4);
    for(int i=1; i <= N; ++i) cin >> v[i];
    init(1, N, 1, tree, v);

    ll diffMax{0};
    for(int i=1; i<= N; ++i){
        diffMax = max(diffMax, v[i] - getMin(1, N, 1, 1, i, tree));
        cout << diffMax << " ";
    }
}