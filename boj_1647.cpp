#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int mst(const vector<vector<pii>> &v, int N) {
    int cnt{0}, result{0}, maxCost{0};
    priority_queue<pii> pq;
    vector<bool> visited(N + 1);
    pq.push({0, 1});

    while (!pq.empty()) {
        int cur = pq.top().second, cost = -pq.top().first;
        pq.pop();

        if (visited[cur]) continue;
        visited[cur] = true;

        result += cost, cnt++, maxCost = max(cost, maxCost);
        if (cnt == N) break;

        for (pii p: v[cur]) pq.push({-p.second, p.first});
    }
    // 두개의 섬으로 만드는 방법은 간단하다. 최소 스패닝 트리로 만들고 제일 유지비 비싼거 빼주면 된다.
    return result - maxCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<pii>> v(N + 1);

    int fir, sec, cost;
    while (M--) {
        cin >> fir >> sec >> cost;
        v[fir].push_back({sec, cost});
        v[sec].push_back({fir, cost});
    }

    cout << mst(v, N) << "\n";
}