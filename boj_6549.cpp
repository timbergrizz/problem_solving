#include <bits/stdc++.h>

#define INF 1000000001
#define FOR(i, N) for(int i=1; i <= N; ++i)
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

pii getMin(vp &tree, int start, ll end, ll node, ll l, ll r) {
    if (end < l || r < start) return {INF, 0};
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) / 2;
    return min(getMin(tree, start, mid, node * 2, l, r), getMin(tree, mid + 1, end, node * 2 + 1, l, r));
}

ll getMax(vp &tree, vl &v, ll start, ll end, int N) {
    if (start == end) return v[start];

    pii cur = getMin(tree, 1, N, 1, start, end);
    ll size = (end - start + 1) * cur.first;
//    cout << start << end << size << endl;
    if (cur.second - 1 >= start) size = max(size, getMax(tree, v, start, cur.second - 1, N));
    if (cur.second + 1 <= end) size = max(size, getMax(tree, v, cur.second + 1, end, N));

    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vp tree(400001);
    vl v(100001);
    while (true) {
        for (pii &it: tree) it = {0, 0};
        fill(v.begin(), v.end(), 0);
        v[0] = INF;

        int N;
        cin >> N;
        if (!N) break;

        FOR(i, N) {
            cin >> v[i];
            update(tree, 1, N, 1, i, v[i]);
        }
        cout << getMax(tree, v, 1, N, N) << "\n";
    }
}