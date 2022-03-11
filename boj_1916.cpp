#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

typedef pair<int, int> pii;

void djikstra(const vector<vector<pii>> &v, vector<int> &dist, int start, int target, int size) {
    priority_queue<pii> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur = pq.top().second, cost = -pq.top().first;
        pq.pop();

        if(dist[target] < cost) continue;

        for (pii it: v[cur]) {
            int n = it.second, nCost = it.first;
            if (dist[n] > cost + nCost) {
                dist[n] = cost + nCost;
                pq.push({-dist[n], n});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<pii>> v(N + 1);
    vector<int> dist(N + 1, INF);

    int fir, sec, cost;
    while(M--) {
        cin >> fir >> sec >> cost;
        v[fir].push_back({cost, sec});
    }

    cin >> fir >> sec;
    djikstra(v, dist, fir, sec, N);
    cout << dist[sec] << '\n';
}