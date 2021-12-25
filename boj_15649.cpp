#include <iostream>

using namespace std;

int a[8];
bool visited[8];
int cnt;
int M, N;

void dfs(int n) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i) cout << a[i] + 1 << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            a[cnt] = i, cnt++;
            dfs(i);
            cnt--, visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(0);
}