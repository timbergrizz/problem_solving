#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef stack<ll> sl;

void dfs(ll cur, sl &s, vvl &v, vl &visited) {
    if (visited[cur]) return;
    visited[cur] = true;

    for (ll it: v[cur]) dfs(it, s, v, visited);

    s.push(cur);
}

void second_dfs(ll cur, vl &s, vvl &v, vl &visited) {
    if (visited[cur]) return;
    visited[cur] = true;
    s.push_back(cur);

    for (ll it: v[cur]) second_dfs(it, s, v, visited);
}

int main() {
    FASTIO
    ll V, E;
    cin >> V >> E;

    ll c1, c2;
    vvl v(V + 1);
    vvl v2(V + 1);
    FOR(i, E) {
        cin >> c1 >> c2;
        v[c1].push_back(c2);
        v2[c2].push_back(c1);
    }

    stack<ll> s;
    vl visited(V + 1);
    FOR(i, V) dfs(i, s, v, visited);
    for (ll &i: visited) i = 0;

    vvl ssc;
    ll i{0};
    while (!s.empty()) {
        ll top = s.top();
        s.pop();

        if (!visited[top]) {
            ssc.push_back(vl());
            second_dfs(top, ssc[i++], v2, visited);
        }
    }
    cout << ssc.size() << "\n";

    for (auto &it: ssc) sort(it.begin(), it.end());
    sort(ssc.begin(), ssc.end());

    for (const auto &it: ssc) {
        for (const auto &i: it) cout << i << " ";
        cout << -1 << "\n";
    }
}