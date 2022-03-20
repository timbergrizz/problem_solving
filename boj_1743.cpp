#include <bits/stdc++.h>

using namespace std;

typedef vector<bool> vi;

int dx[4]{1, -1, 0, 0};
int dy[4]{0, 0, 1, -1};

int N, M, K;
void dfs(int y, int x, int & size, vector<vi> &visited, const vector<vi> &v){
    visited[y][x] = true, size++;
//    cout << y <<  " " << x << " " << size << "\n";

    for(int i=0; i < 4; ++i){
        int px = x + dx[i], py = y + dy[i];
        if(px <= 0 || px > M || py <= 0 || py > N) continue;
        if(!v[py][px] || visited[py][px]) continue;

        dfs(py, px, size, visited, v);
    }
}

int main() {
    cin >> N >> M >> K;
    vector<vi> v(N + 1, vi(M + 1));
    vector<vi> visited(N + 1, vi(M + 1));

    int x, y;
    for (int i = 0; i < K; ++i) {
        cin >> y >> x;
        v[y][x] = true;
    }

    int result{0};
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if(!visited[i][j] && v[i][j]){
                int size{0};
                dfs(i, j, size, visited, v);
                result = max(size, result);
            }
        }
    }
    cout << result << "\n";

}