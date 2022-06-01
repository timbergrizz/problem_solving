#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1e9
#define f first
#define s second
#define FOR(i, n) for(ll i=1; i <= n; ++i)
#define t(p) [p.f][p.s]
#define check(i, N) i <= 0 || i > N

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> ppl;

ll v[1010][1010]{0,}, cost[1010][1010]{0,};
int dx[5]{0, 1, -1,}, dy[5]{0, 0, 0, 1, -1};


ll dijkstra(ll N) {
    priority_queue<ppl> pq;
    pq.push({0, {1, 1}});
    cost[1][1] = 0;

    while (!pq.empty()) {
        ppl top = pq.top();
        pq.pop();

        ll curCost = -top.f;
        pll curPos = top.s;

        FOR(i, 4) {
            pll next = {curPos.f + dy[i], curPos.s + dx[i]};

            if (check(next.f, N) || check(next.s, N)) continue;

            ll nCost = max(curCost, abs(v t(curPos) - v t(next)));
            if (cost t(next) <= nCost) continue;

            cost t(next) = nCost;
            pq.push({-nCost, next});
        }
    }

    return cost[N][N];
}

int main() {
    FASTIO
    ll N;
    cin >> N;
    FOR(i, N) {
        FOR(j, N) {
            cin >> v[i][j];
            cost[i][j] = INF;
        }
    }

    cout << dijkstra(N) << "\n";
}