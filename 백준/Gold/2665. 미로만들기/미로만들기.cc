#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
#define f first
#define s second
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<int, pii> pip;

int dx[5]{0, 1, -1, 0, 0}, dy[5]{0, 0, 0, 1, -1};

int dijkstra(vvi &v, vvi &dist, int N) {
    priority_queue<pip> pq;
    pq.push({0, {1, 1}});
    while (!pq.empty()) {
        pip top = pq.top();
        pq.pop();

        int cost = -top.f;
        pii cur = top.s;
//        cout << 1 << cur.first << cur.second << endl;

        FOR(i, 4) {
            pii next = {cur.f + dy[i], cur.s + dx[i]};
//            cout << 2 << next.first << next.second << endl;

            if (next.f <= 0 || next.s <= 0) continue;
            if (next.f > N || next.s > N) continue;

            if (dist[next.f][next.s] <= v[next.f][next.s] + cost) continue;

            dist[next.f][next.s] = v[next.f][next.s] + cost;
            pq.push({-dist[next.f][next.s], next});
        }
    }

    return dist[N][N];
}

int main() {
    int N;
    cin >> N;
    vvi v(N + 1, vi(N + 1)), dist(N + 1, vi(N + 1, 1e9));

    string temp;
    FOR(i, N) {
        cin >> temp;
        FOR(j, N) v[i][j] = (temp[j - 1] == '0' ? 1 : 0);
    }

    cout << dijkstra(v, dist, N) << "\n";
}