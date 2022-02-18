#include <bits/stdc++.h>

using namespace std;

int N;
bool v[101][101]{false, }, result[101][101]{false, }, visited[101];

void bfs(int n) {
    memset(visited, false, sizeof visited);

    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int f = q.front();
        q.pop();

        for (int i = 1; i <= N; ++i) {
            if (visited[i] || !v[f][i]) continue;
            q.push(i);
            result[n][i] = true, visited[i] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) cin >> v[i][j];
    }

    for (int i = 1; i <= N; ++i) bfs(i);

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) cout << result[i][j] << " ";
        cout << "\n";
    }
}