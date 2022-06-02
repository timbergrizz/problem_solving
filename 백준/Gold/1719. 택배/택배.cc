#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 200001
#define f first
#define s second
#define FOR(i, n) for(ll i=1; i <= n; ++i)
#define t(p) [p.f][p.s]
#define check(i, N) i <= 0 || i > N

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> ppl;

ll v[202][202]{0,}, cost[202][202]{0,}, par[202][202]{0,};


void floyd_warshall(ll N) {
    FOR(i, N) {
        FOR(j, N) {
            if (i == j) cost[i][j] = 0;
            else if (!v[i][j]) cost[i][j] = INF;
            else cost[i][j] = v[i][j], par[i][j] = j, par[j][i] = i;
        }
    }

    FOR(k, N) {
        FOR(i, N) {
            FOR(j, N) {
                if (cost[i][k] + cost[k][j] >= cost[i][j]) continue;

                cost[i][j] = cost[i][k] + cost[k][j];
                par[i][j] = par[i][k];
            }
        }
    }
}

int main() {
    FASTIO
    int N, M;
    cin >> N >> M;
    int c1, c2, c3;
    while (M--) {
        cin >> c1 >> c2 >> c3;
        v[c1][c2] = c3, v[c2][c1] = c3;
    }

    floyd_warshall(N);
    FOR(i, N) {
        FOR(j, N) {
            if (i == j) cout << "- ";
            else cout << par[i][j] << " ";
        }
        cout << "\n";
    }
}