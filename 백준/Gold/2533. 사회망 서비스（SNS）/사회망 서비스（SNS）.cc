#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX 1010101
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

ll dp[MAX][2];
vvl v, adj;

void tree(ll cur, ll prev) {
    for (auto n: v[cur]) {
        if (n == prev) continue;

        adj[cur].push_back(n);
        tree(n, cur);
    }
}

ll dfs(ll cur, ll type) {
    ll &ret = dp[cur][type];
    if (ret != -1) return ret;

    if (adj[cur].empty()) return ret = type;

    if (!type) {
        ret = 0;
        for (ll i: adj[cur]) ret += dfs(i, 1);
    } else {
        ret = 1;
        for (ll i : adj[cur]) ret += min(dfs(i, 1), dfs(i, 0));
    }

    return ret;
}

int main() {
    FASTIO
    ll N, c1, c2;
    cin >> N;
    v = vvl(N + 1), adj = vvl(N + 1);

    FOR(i, N - 1) {
        cin >> c1 >> c2;
        v[c1].push_back(c2);
        v[c2].push_back(c1);
    }

    tree(1, 0);
    memset(dp, -1, sizeof dp);

    cout << min(dfs(1, 0), dfs(1, 1));
}