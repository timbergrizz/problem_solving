#include <bits/stdc++.h>

#define INF 50001
#define MAX 1010101
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define FOR(i, n) for(int i=1; i <= n; ++i)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<pll> vp;
typedef vector<ll> vl;

ll v[INF], minTree[INF * 4], maxTree[INF * 4];
ll N;

ll minInit(ll node = 1, ll start = 1, ll end = N) {
    if (start == end) return minTree[node] = v[start];

    ll mid = (start + end) >> 1;
    return minTree[node] = min(minInit(node << 1, start, mid), minInit(node << 1 | 1, mid + 1, end));
}

ll maxInit(ll node = 1, ll start = 1, ll end = N) {
    if (start == end) return maxTree[node] = v[start];

    ll mid = (start + end) >> 1;
    return maxTree[node] = max(maxInit(node << 1, start, mid), maxInit(node << 1 | 1, mid + 1, end));
}

ll getMin(ll l, ll r, ll node = 1, ll start = 1, ll end = N) {
    if (end < l || r < start) return MAX;
    if (l <= start && end <= r) return minTree[node];

    ll mid = (start + end) >> 1;
    return min(getMin(l, r, node << 1, start, mid), getMin(l, r, node << 1 | 1, mid + 1, end));
}

ll getMax(ll l, ll r, ll node = 1, ll start = 1, ll end = N) {
    if (end < l || r < start) return 0;
    if (l <= start && end <= r) return maxTree[node];

    ll mid = (start + end) >> 1;
    return max(getMax(l, r, node << 1, start, mid), getMax(l, r, node << 1 | 1, mid + 1, end));
}

void init() {
    memset(v, 0, sizeof v);
    memset(maxTree, 0, sizeof maxTree);
    FOR(i, INF * 4 - 1) minTree[i] = MAX;
}

int main() {
    FASTIO;

    init();
    ll Q, c1, c2;
    cin >> N >> Q;

    FOR(i, N) cin >> v[i];
    minInit();
    maxInit();

    FOR(i, Q) {
        cin >> c1 >> c2;
        ll minVal = getMin(c1, c2), maxVal = getMax(c1, c2);
        cout << maxVal - minVal << "\n";
    }
}