#include <bits/stdc++.h>

#define INF 1e9
#define FOR(i, n) for(int i=1; i <= n; ++i)
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

void djikstra(const vector<vi> &v, vi &dist, int n, int start) {
    priority_queue<pii> pq;
    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty()) {
        pii t = pq.top();
        pq.pop();
        int cost = -t.first, cur = t.second;
        FOR(i, n) {
            if(!v[cur][i]) continue;
            if(dist[i] <= cost + v[cur][i]) continue;

            dist[i] = cost + v[cur][i];
            pq.push({-dist[i], i});
        }
    }
}

int main() {
    int x, n, m;
    cin >> n >> m >> x;

    vector<vi> v(n + 1, vi(n + 1));
    vi dist;
    vi dist_go(n + 1);
    vi dist_back(n + 1, INF);

    int fir, sec, cost;
    FOR(i, m){
        cin >> fir >> sec >> cost;
        v[fir][sec] = cost;
    }

    FOR(i, n){
        if(i == x) continue;
        dist = vi(n + 1, INF);
        djikstra(v, dist, n, i);
        dist_go[i] = dist[x];
    }

    djikstra(v, dist_back, n, x);
    int result{0};
    FOR(i, n) {
        dist_go[i] += dist_back[i];
        result = max(result, dist_go[i]);
    }
    cout << result << "\n";

}