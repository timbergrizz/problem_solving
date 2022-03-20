#include <bits/stdc++.h>

#define FOR(i, n) for(int i=0; i < n; ++i)
using namespace std;

int v[501][501]{0,}, cnt[501][501]{0,};
bool visited[501][501]{false,};
int px[4]{1, -1, 0, 0}, py[4]{0, 0, 1, -1};
int M, N, result{0};

// 메모리제이션 dfs.
// 이미 방문한 노드에 대해서는
int dfs(int x, int y) {
    if (x == N - 1 && y == M - 1) return 1;

    if (visited[y][x]) return cnt[y][x];
    visited[y][x] = true;

    FOR(i, 4) {
        int dx = x + px[i], dy = y + py[i];
        if (dx < 0 || dx >= N || dy < 0 || dy >= M) continue;
        if (v[y][x] <= v[dy][dx]) continue;

        cnt[y][x] += dfs(dx, dy);
    }

    return cnt[y][x];
}

int main() {
    cin >> M >> N;
    FOR(i, M) FOR(j, N) cin >> v[i][j];
    cout << dfs(0, 0) << "\n";
}