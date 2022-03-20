#include <bits/stdc++.h>

#define INF 1e9
#define FOR(i, N) for(int i=0; i < N; ++i)
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
int px[4]{1, -1, 0, 0}, py[4]{0, 0, 1, -1};

int v[126][126];
int dist[126][126];

void djikstra(int N) {
    priority_queue<pair<int, pii>> pq;
    pq.push({-v[0][0], {0, 0}});
    dist[0][0] = v[0][0];

    while (!pq.empty()) {
        int cost = -pq.top().first;
        pii cur = pq.top().second;
        pq.pop();

        if (dist[cur.second][cur.first] > dist[N - 1][N - 1]) continue;
        for (int i = 0; i < 4; ++i) {
            int dy = cur.first + py[i], dx = cur.second + px[i];

            if (dx < 0 || dy < 0 || dx >= N || dy >= N) continue;
            if (cost + v[dy][dx] >= dist[dy][dx]) continue;

            dist[dy][dx] = cost + v[dy][dx];
            pq.push({-dist[dy][dx], {dy, dx}});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cnt{1};
    while (true) {
        int N;
        cin >> N;
        if (!N) break;

        FOR(i, N){
            FOR(j, N) {
                cin >> v[i][j];
                dist[i][j] = INF;
            }
        }

        djikstra(N);

        cout << "Problem " << cnt++ << ": " << dist[N - 1][N - 1] << "\n";
    }
}