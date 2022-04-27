#include <bits/stdc++.h>

#define FOR(i, N) for(int i=0; i < N; ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vl;

ll update(vl & tree, int start, int end, int node, int idx) {
//    cout << start << end << endl;
    if (end < idx || idx < start) return tree[node];
    if (start == end) return tree[node] += 1;

    int mid = (start + end) / 2;
    return tree[node] = update(tree, start, mid, node * 2, idx) + update(tree,mid + 1, end, node * 2 + 1, idx);
}

ll sum(vl & tree, int start, int end, int node, int l, int r) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return tree[node];

    int mid = (start + end) / 2;
    return sum(tree, start, mid, node * 2, l, r) + sum(tree, mid + 1, end, node * 2 + 1, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    vl tree(1600000);
    vector<pii> v(400000);

    FOR(testNum, T) {
        for(ll &i : tree) i = 0;
        for (pii it: v) it.first = it.second = 0;

        int N, M, K;
        cin >> N >> M >> K;

        FOR(i, K) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.begin() + K);

        ll result{0};
        FOR(i, K) {
//            FOR(j, 2 << M) cout << tree[j] << " ";
//            cout << endl;

            if(v[i].second < M) result += sum(tree, 1, M, 1, v[i].second + 1, M);
            update(tree, 1, M, 1, v[i].second);
        }
        cout << "Test case " << testNum + 1<< ": " << result << "\n";
    }
}