#include <bits/stdc++.h>

#define INF 1e9
#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

typedef pair<int, int> pii;

void Dijkstra(const vector<vector<pii>> &v, vector<int> &dist, int startPoint, int V) {
    priority_queue<pii> pq;
    pq.push({0, startPoint});
    dist[startPoint] = 0;
    // 시작점을 설정한다.
    // priority queue를 이용해 가까운 노드부터 방문해 처리할 수 있다.
    // priority queue를 사용하는 이유는 시간 복잡도를 줄이기 위해

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        // 현재 방문중인 노드의 비용과 위치를 저장한다.

        for (pii i: v[cur]) {
            //연결된 모든 노드에 대해 최단 경로 여부를 확인한다.
            int n = i.first, nCost = i.second;
            if (dist[n] > cost + nCost) {
                dist[n] = cost + nCost;
                pq.push({-dist[n], n});
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    int start;
    cin >> start;

    int fir, sec, cost;
    vector<vector<pii>> v(V + 1);
    vector<int> dist(V + 1, INF);

    FOR(i, E) {
        cin >> fir >> sec >> cost;
        v[fir].push_back({sec, cost});
    }

    Dijkstra(v, dist, start, V);
    FOR(i, V) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}