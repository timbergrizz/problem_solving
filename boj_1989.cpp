#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> ppi;
typedef vector<ll> vi;
typedef vector<pii> vp;

pii update(vp &tree, vi &v, ll start, ll end, ll node, ll idx, ll val) {
    if (idx < start || end < idx) return tree[node];
    if (start == end) return tree[node] = {val, idx};

    ll mid = (start + end) / 2;
    pii fir = update(tree, v, start, mid, node * 2, idx, val);
    pii sec = update(tree, v, mid + 1, end, node * 2 + 1, idx, val);
    return tree[node] = {fir.first + sec.first, (v[fir.second] < v[sec.second] ? fir.second : sec.second)};
}

pii getVal(vp &tree, vi &v, ll start, ll end, ll node, ll l, ll r) {
    if (r < start || end < l) return {0, 0};
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) / 2;
    pii fir = getVal(tree, v, start, mid, node * 2, l, r);
    pii sec = getVal(tree, v, mid + 1, end, node * 2 + 1, l, r);
    return {fir.first + sec.first, (v[fir.second] < v[sec.second] ? fir.second : sec.second)};
}

ppi getMax(vp &tree, vi &v, ll start, ll end, ll N) {
    if (start == end) return {v[start] * v[start], {start, start}};

    pii cur = getVal(tree, v, 1, N, 1, start, end);
    ppi result = {cur.first * v[cur.second], {start, end}};

    if (cur.second - 1 >= start) {
        ppi le= getMax(tree, v, start, cur.second - 1, N);
        if (le.first > result.first) result = le;
    }
    if (cur.second + 1 <= end) {
        ppi gr = getMax(tree, v, cur.second + 1, end, N);
        if (gr.first > result.first) result = gr;
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    ll treeSize = (1 << ((int) ceil(log2(N)) + 1)) + 1000;
    vi v(N + 1);
    vp tree(treeSize);
    v[0] = 1e9;

    FOR(i, N) {
        cin >> v[i];
        update(tree, v, 1, N, 1, i, v[i]);
    }

    ppi result = getMax(tree, v, 1, N, N);
    cout << result.first << "\n" << result.second.first << " " << result.second.second << "\n";
}