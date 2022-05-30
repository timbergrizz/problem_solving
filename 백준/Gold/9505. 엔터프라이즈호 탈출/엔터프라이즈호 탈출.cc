#include <bits/stdc++.h>

#define INF 1e9
#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define FOR(i, N) for(int i=1; i <= N; ++i)
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pii;
typedef pair<ll, pii> ppi;
int dx[]{0, 1, -1, 0, 0}, dy[]{0, 0, 0, 1, -1};
ll v[1010][1010]{0, };
ll cost[1010][1010]{0, };

ll dijkstra(pii start, int n, int m) {
    priority_queue<ppi> pq;
    pq.push({0, start});
    cost[start.f][start.s] = 0;

    ll result = INF;
    while (!pq.empty()) {
        ppi top = pq.top();
        pq.pop();

        ll curCost = -top.f;
        pii cur = top.s;

        FOR(i, 4) {
            pii next = {cur.f + dy[i], cur.s + dx[i]};

            if (next.f <= 0 || next.f > n || next.s <= 0 || next.s > m) {
                result = min(result, curCost);
                continue;
            }
            if (cost[next.f][next.s] <= curCost + v[next.f][next.s]) continue;

            cost[next.f][next.s] = curCost + v[next.f][next.s];
            pq.push({-cost[next.f][next.s], next});
        }
    }

    return result;
}


int main() {
    FASTIO
    int T;
    cin >> T;

    int c1, c2, c3, c4;
    char temp;

    vl m(128);
    while (T--) {
        memset(v, 0, sizeof v);
        FOR(i, 1010) {
            FOR(j, 1010) cost[i][j] = INF;
        }

        cin >> c1 >> c2 >> c3;

        while (c1--) {
            cin >> temp >> c4;
            m[temp] = c4;
        }

        pii start;
        FOR(i, c3) {
            FOR(j, c2) {
                cin >> temp;
                v[i][j] = m[temp];
                if (temp == 'E') start = {i, j};
            }
        }

        cout << dijkstra(start, c3, c2) << "\n";
    }
}