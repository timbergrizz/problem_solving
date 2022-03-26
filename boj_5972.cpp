#include <bits/stdc++.h>
#define INF 1e9
#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

typedef pair<int, int> pii;

void dijkstra(const vector<vector<pii>> &v, vector<int> &dist) {
    priority_queue<pii> pq;
    pq.push({0, 1});
    dist[0] = 0;

    while(!pq.empty()){
        int cur = pq.top().second, cost = -pq.top().first;
        pq.pop();

        for(pii i : v[cur]){
            int curCost = cost + i.second;
            if(curCost >= dist[i.first]) continue;

            dist[i.first] = curCost;
            pq.push({-curCost, i.first});
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pii>> v(N + 1);
    vector<int> dist(N + 1, INF);

    int fir, sec, cost;
    FOR(i, M) {
        cin >> fir >> sec >> cost;
        v[fir].push_back({sec, cost});
        v[sec].push_back({fir, cost});
    }
    dijkstra(v, dist);
    cout << dist[N] << "\n";
}