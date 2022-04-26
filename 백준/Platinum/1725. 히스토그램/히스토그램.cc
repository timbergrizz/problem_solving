#include <bits/stdc++.h>

#define INF 1e9
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vl;
typedef vector<pii> vp;

pii update(vp &tree, ll start, ll end, ll node, ll idx, ll val) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] = {val, idx};

    ll mid = (start + end) / 2;
    return tree[node] = min(update(tree, start, mid, node * 2, idx, val),
                            update(tree, mid + 1, end, node * 2 + 1, idx, val));
}

pii getMin(vp &tree, ll start, ll end, ll node, ll l, ll r) {
    if (end < l || r < start) return {INF, 0};
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) / 2;
    return tree[node] = min(getMin(tree, start, mid, node * 2, l, r), getMin(tree, mid + 1, end, node * 2 + 1, l, r));
}

ll getMax(vp &tree, vl &v, ll start, ll end, ll N) {
    if (start == end) return v[start];

    pii cur = getMin(tree, 1, N, 1, start, end);
    ll result = cur.first * (end - start + 1);

    if (cur.second + 1 <= end) result = max(result, getMax(tree, v, cur.second + 1, end, N));
    if (cur.second - 1 >= start) result = max(result, getMax(tree, v, start, cur.second - 1, N));
    return result;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    int treeSize = 1 << ((int) ceil(log2(N)) + 1);
    vl v(N + 1);
    vp tree(treeSize);

    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        update(tree, 1, N, 1, i, v[i]);
    }

    cout << getMax(tree, v, 1, N, N) << "\n";
}