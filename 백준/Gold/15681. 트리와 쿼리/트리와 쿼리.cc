#include <bits/stdc++.h>
#define FOR(i, N) for(int i=1; i <= N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

vvl v;
vl visited;

ll dfs(ll cur){
    visited[cur] = 1;

    for(ll i : v[cur]){
        if(!visited[i]) visited[cur] += dfs(i);
    }
    return visited[cur];
}

int main() {
    FASTIO;
    ll N, R, Q, c1, c2; cin >> N >> R >> Q;
    v.resize(N + 1);
    visited.resize(N + 1);

    FOR(i, N - 1){
        cin >> c1 >> c2;
        v[c1].push_back(c2);
        v[c2].push_back(c1);
    }

    dfs(R);

    FOR(i, Q){
        cin >> c1;
        cout << visited[c1] << "\n";
    }
}