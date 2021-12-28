#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[8], v[8];
bool visit[8];

void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i) cout << arr[v[i]] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (!visit[i]) {
            visit[i] = true, v[cnt] = i;
            dfs(cnt + 1);
            visit[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    dfs(0);
}