#include <bits/stdc++.h>

#define FOR(i, N) for(int i=0; i < N; ++i)
#define INF 1e9
using namespace std;

int trace[1001]{0,};

void djikstra(const vector<vector<pair<int, int>>> &v, vector<int> &cost, int N, int start, int end) {
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    cost[start] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second, cCost = -pq.top().first;
        pq.pop();

        if (cost[cur] < cCost) continue;
        for (auto it: v[cur]) {
            int next = it.second, nCost = it.first;

            if (nCost + cCost < cost[next]) {
                cost[next] = nCost + cCost;
                trace[next] = cur;
                pq.push({-cost[next], next});
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> v(N + 1);

    int fir, sec, c;
    while (M--) {
        cin >> fir >> sec >> c;
        v[fir].push_back({c, sec});
    }

    vector<int> cost(N + 1, INF);
    cin >> fir >> sec;
    djikstra(v, cost, N, fir, sec);

    auto result = cost[sec];
    cout << result << "\n";
    stack<int> s;
    int pos = sec;
    while (pos) {
        s.push(pos) ;
        pos = trace[pos];
    }
    cout << s.size() << "\n";
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}