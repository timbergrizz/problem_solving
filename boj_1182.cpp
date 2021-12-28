#include <iostream>

using namespace std;

int N, S, cnt{0};
int v[21]{0, };

void dfs(int idx, int sum, int size) {
    if (sum == S && size != 0)
        cnt++;

    if (idx == N) return;

    for (int i = idx + 1; i <= N; ++i) {
        dfs(i, sum + v[i], size + 1);
    }
}

int main() {
    cin >> N >> S;
    for (int i = 1; i <= N; ++i) cin >> v[i];
    dfs(0, 0, 0);

    cout << cnt << endl;
}