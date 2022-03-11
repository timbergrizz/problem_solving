#include <bits/stdc++.h>

using namespace std;

bool v[101][101]{false,}, visited[101][101]{false,};
int dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};
int M, N, K;

void dfs(int y, int x, int &level) {
//    cout << level << " " << y << " " << x << "\n";
    if (visited[y][x] || v[y][x]) return;
    ++level, visited[y][x] = true;

    for (int i = 0; i < 4; ++i) {
        int px = x + dx[i], py = y + dy[i];
        if (px < 0 || px >= N || py < 0 || py >= M) continue;
        if (v[py][px] || visited[py][px]) continue;

        dfs(py, px, level);
    }
}

int main() {
    cin >> M >> N >> K;
    while (K--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = x1; j < x2; ++j) {
            for (int i = y1; i < y2; ++i) {
                v[i][j] = true;
            }
        }
    }


    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
//            cout << v[i][j] << " ";
            if (!v[i][j] && !visited[i][j]) {
                int level{0};
                dfs(i, j, level);
                pq.push(level);
            }
        }
//        cout << endl;
    }

    cout << pq.size() << "\n";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << "\n";
}