#include <bits/stdc++.h>
#define INF 10000001
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpll;


void init(vpll & tree, vl & v, ll start, ll end, ll node){
    if(start == end) {
        tree[node] = {v[start], start};
        return;
    }

    ll mid = (start + end) / 2;
    init(tree, v, start, mid, node * 2);
    init(tree, v, mid + 1, end, node * 2 + 1);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

pll minSal(vpll & tree, ll start, ll end, ll node, ll l, ll r){
    if(end < l || r < start) return {INF, 0};
    if(l <= start && end <= r) return tree[node];

    ll mid = (start + end) / 2;
    pll fir = minSal(tree, start, mid, node * 2, l, r);
    pll sec = minSal(tree, mid + 1, end, node * 2 + 1, l, r);
    return min(fir, sec);
}

ll maxSal(vpll &tree, vl &v, ll start, ll end, ll N){

    if (start == end) return v[start];

    pll cur = minSal(tree, 1, N, 1, start, end);

    ll result = cur.first * (end - start + 1);

    if(cur.second + 1 <= end) result = max(result, maxSal(tree, v, cur.second + 1, end, N));
    if(cur.second - 1 >= start) result = max(result, maxSal(tree, v, start, cur.second - 1, N));

    return result;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    vl v(N + 1);
    int treeSize = 1 << ((int)ceil(log2(N)) + 1);
    vpll tree(treeSize, {INF, 0});

    for(int i=1; i<= N; ++i) cin >> v[i];
    init(tree, v, 1, N, 1);

    cout << maxSal(tree, v, 1, N, N) << "\n";
}