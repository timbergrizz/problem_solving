#include <bits/stdc++.h>

#define INF 9223372036854775807
#define FOR(i, N) for(int i=0; i < N; ++i)
using namespace std;
typedef pair<long long, long long> pii;

vector<pair<int, int>> v[100001];
int visible[100001];
long long dist[100001];

void dijkstra(int N) {
    priority_queue<pii> pq;
    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
        long long cur = pq.top().second, cost = -pq.top().first;
        pq.pop();

        if (cost > dist[N - 1] || cost > dist[cur]) continue;
        //입력된 코스트가 현재보다 클때도 확인할 필요가 없다.

        for (int i = 0; i < v[cur].size(); ++i) {
            if (visible[v[cur][i].second]) continue;

            if (cost + v[cur][i].first < dist[v[cur][i].second]) {
                dist[v[cur][i].second] = cost + v[cur][i].first;
                pq.push({-(v[cur][i].first + cost), v[cur][i].second});
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

    FOR(i, N) {
        dist[i] = INF;
        cin >> visible[i];
    }
    visible[N - 1] = 0;

    int fir, sec, cost;
    while (M--) {
        cin >> fir >> sec >> cost;
        v[fir].push_back({cost, sec});
        v[sec].push_back({cost, fir});
    }
    dijkstra(N);

    cout << (dist[N - 1] == INF ? -1 : dist[N - 1]) << "\n";
}