#include <bits/stdc++.h>

#define INF 1e9
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pip;
typedef vector<int> vi;

void dijkstra(const vector<vector<pip>> &v, vector<vi> &dist, int M) {
    priority_queue<pip> pq;
    dist[1][0] = 0;
    pq.push({0, {0, 1}});

    while (!pq.empty()) {
        pip cur = pq.top();
        int curN = cur.second.second, cost = cur.second.first, time = -cur.first;
        pq.pop();

        for (pip it: v[curN]) {
            int nextTime = time + it.first, nextCost = cost + it.second.first;
            int next = it.second.second;

            if (nextCost > M) continue;
            if (nextTime >= dist[next][nextCost]) continue;

            dist[next][nextCost] = nextTime;
            pq.push({-nextTime, {nextCost, next}});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        cin >> N >> M >> K;

        vector<vector<pip>> v(N + 1);
        // 굳이 조건에 비용 고려할 필요 없다.
        // 이차원 배열로 금액 받고, 이걸로 처리하면 오케이
        vector<vi> dist(N + 1, vi(M + 1, INF));

        int fir, target, cost, time;
        while (K--) {
            cin >> fir >> target >> cost >> time;
            v[fir].push_back({time, {cost, target}});
        }

        dijkstra(v, dist, M);

        int result = INF;
        for (int i: dist[N]) result = min(i, result);

        if (result == INF) cout << "Poor KCM" << "\n";
        else cout << result << "\n";
    }
}

