#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, init, N) for(int i=init; i <= N; ++i)
#define INF 100001

using namespace std;

int tree[INF * 9], v[INF * 2];

int update(int start, int end, int node, int pos, int val) {
    if (end < pos || pos < start) return tree[node];
    if (start == end) return tree[node] = val;

    int mid = (start + end) >> 1;
    return tree[node] = update(start, mid, (node << 1), pos, val) + update(mid + 1, end, (node << 1) + 1, pos, val);
}

int get_sum(int start, int end, int node, int l, int r) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) >> 1;
    return get_sum(start, mid, node << 1, l, r) + get_sum(mid + 1, end, node << 1 | 1, l, r);
}

int main() {
    FASTIO
    int T, N, M, c1;
    cin >> T;
    while (T--) {
        memset(tree, 0, sizeof tree);
        memset(v, 0, sizeof v);

        cin >> N >> M;
        int idx = M + 1;

        FOR(i, idx, N + M) {
            update(1, N + M, 1, i, 1);
            v[i - M] = i;
        }

        idx = M;
        FOR(i, 1, M) {
            cin >> c1;
            cout << get_sum(1, N + M, 1, 0, v[c1] - 1) << " ";
            update(1, N + M, 1, v[c1], 0);
            v[c1] = idx--;
            update(1, N + M, 1, v[c1], 1);
        }
        cout << "\n";
    }
}