#include <bits/stdc++.h>

#define FOR(i, END) for(int i=1; i <= END; ++i)
#define INF 1e9 + 1
#define MAX 101010
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
typedef long long ll;
ll v[MAX], tree[MAX * 4], N;


ll init(ll start = 1, ll end = N, ll node = 1) {
    if (start == end) return tree[node] = 1;

    ll mid = (start + end) >> 1;
    return tree[node] = init(start, mid, node << 1) + init(mid + 1, end, node << 1 | 1);
}

ll get_sum(ll l, ll r, ll start = 1, ll end = N, ll node = 1) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return tree[node];

    ll mid = (start + end) >> 1;
    return get_sum(l, r, start, mid, node << 1) + get_sum(l, r, mid + 1, end, node << 1 | 1);
}

ll update(ll idx, ll start = 1, ll end = N, ll node = 1) {
    if (end < idx || idx < start) return tree[node];
    if (start == end) return tree[node] = 0;

    ll mid = (start + end) >> 1;
    return tree[node] = update(idx, start, mid, node << 1) + update(idx, mid + 1, end, node << 1 | 1);
}

int main() {
    FASTIO

    cin >> N;
    init();

    int c1;
    FOR(i, N) {
        cin >> c1;
        v[c1] = i;
    }

    FOR(i, N) {
        ll rev_idx = N - i + 1;
        if(rev_idx < i) break;
        cout << get_sum(1, v[i] - 1) << "\n";
        update(v[i]);

        if(rev_idx <= i) break;
        cout << get_sum(v[rev_idx] + 1, N) << "\n";
        update(v[rev_idx]);
    }
}