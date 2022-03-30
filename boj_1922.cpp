#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int mst(const vector<vector<pii>> &v, int N) {
    priority_queue<pii> pq;
    vector<bool> visited(N + 1);
    int cnt{0}, result{0};
    pq.push({0, 1});

    while (!pq.empty()) {
        int cur = pq.top().second, cost = -pq.top().first;
        pq.pop();

        if (visited[cur]) continue;
        visited[cur] = true, result += cost, cnt++;
        if(cnt == N) break;

        for(pii it : v[cur]){
            pq.push({-it.second, it.first});
        }
    }
    return result;
}

int main() {
    int N, M;
    cin >> N >> M;
    int fir, sec, cost;
    vector<vector<pii>> v( N + 1);

    while (M--) {
        cin >> fir >> sec >> cost;
        v[fir].push_back({sec, cost});
        v[sec].push_back({fir, cost});
    }
    cout << mst(v, N) << "\n";
}