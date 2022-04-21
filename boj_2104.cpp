#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<pii> vp;
typedef vector<ll> vi;

pii update(vp &tree, vi &v, ll start, ll end, ll node, ll idx, ll val) {
    if (idx < start || idx > end) return tree[node];
    if (start == end) return tree[node] = {val, idx};

    ll mid{(start + end) / 2};
    pii fir = update(tree, v, start, mid, node * 2, idx, val);
    pii sec = update(tree, v, mid + 1, end, node * 2 + 1, idx, val);
    return tree[node] = {fir.first + sec.first, (v[fir.second] < v[sec.second] ? fir.second : sec.second)};
}

pii getVal(vp &tree, vi &v, ll start, ll end, ll node, ll l, ll r) {
    if (r < start || end < l) return {0, 0};
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) / 2;
    pii left = getVal(tree, v, start, mid, node * 2, l, r);
    pii right = getVal(tree, v, mid + 1, end, node * 2 + 1, l, r);

    return {left.first + right.first, (v[left.second] < v[right.second] ? left.second : right.second)};
}

//탐색을 수행할 때
// 퀵 정렬의 형태로도 분할정복을 사용할 수 있다.
// 꼭 절반으로만 문제를 나눌 필요는 없다.
ll getMax(vp &tree, vi &v, ll l, ll r, ll N) {
    if (l == r) return v[l] * v[l];

    pii cur = getVal(tree, v, 1, N, 1, l, r);
    ll curMax = cur.first * v[cur.second];
//    cout << l << " " << r << " " << cur.first << " " << cur.second << endl;

    if (cur.second - 1 >= l) curMax = max(curMax, getMax(tree, v, l, cur.second - 1, N));
    if (cur.second + 1 <= r) curMax = max(curMax, getMax(tree, v, cur.second + 1, r, N));
    return curMax;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    int treeSize = 400010;
    vp tree(treeSize);
    vi v(N + 1);
    v[0] = 1e9;

    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        update(tree, v, 1, N, 1, i, v[i]);
    }

//    for(pii it : tree) cout << it.first << " "<< it.second << endl;
    cout << getMax(tree, v, 1, N, N) << endl;
}