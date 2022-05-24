#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};

ll djikstra(vvi &v, vvi &dist, int N, int M) {
    priority_queue<pair<int, pii>> pq;
    pq.push({0, {1, 1}});
    dist[1][1] = 0;

    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();

        int cost = -t.first;
        pii cur = t.second;
//        cout << cost << endl;

        for (int i = 0; i < 4; ++i) {
            pii next = {cur.first + dx[i], cur.second + dy[i]};
            if (next.first <= 0 || next.second <= 0) continue;
            if (next.first > M || next.second > N) continue;

//            cout << next.first << next.second << endl;
            if (dist[next.first][next.second] <= cost + v[next.first][next.second]) continue;

            dist[next.first][next.second] = cost + v[next.first][next.second];
            pq.push({-dist[next.first][next.second], next});
        }
    }
    return dist[M][N];
}

int main() {
    int N, M;
    cin >> N >> M;
    vvi graph(M + 1, vi(N + 1)), dist(M + 1, vi(N + 1, 10101));

    string temp;
    for (int i = 1; i <= M; ++i) {
        cin >> temp;
        for (int j = 1; j <= N; ++j) graph[i][j] = temp[j-1] - '0';
    }

    cout << djikstra(graph, dist, N, M) << "\n";
}