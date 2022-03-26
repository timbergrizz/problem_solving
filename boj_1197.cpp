#include <bits/stdc++.h>

#define FOR(i, n) for(int i=1; i<=n; ++i)
using namespace std;

typedef pair<int, int> pii;

// 최소 스패닝 트리를 구하기 위한 프림 알고리즘
// 전체적으로 알고리즘이 다익스트라 느낌이다.
// 다익스트라인데 이제 노드를 한번만 방문하는

int prim(const vector<vector<pii>> &v, int V) {
    // 방문했던 노드를 다시 방문하면 안된다. 그럼 사이클 발생한다.
    vector<bool> visited(V + 1);
    priority_queue<pii> pq;
    int answer{0}, cnt{0};

    for (pii i: v[1]) pq.push({-i.second, i.first});
    visited[1] = true;

    while (!pq.empty()) {
        int cur = pq.top().second, cost = -pq.top().first;
        pq.pop();

        if (visited[cur]) continue;
        visited[cur] = true;
        answer += cost, cnt++;
        if (cnt == V - 1) break;

        for (pii i: v[cur]) {
            int next = i.first, nextCost = i.second;
            pq.push({-nextCost, next});
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;
    int fir, sec, weight;

    vector<vector<pii>> v(V + 1);

    FOR(i, E) {
        cin >> fir >> sec >> weight;
        v[fir].push_back({sec, weight});
        v[sec].push_back({fir, weight});
    }

    cout << prim(v, V);
}