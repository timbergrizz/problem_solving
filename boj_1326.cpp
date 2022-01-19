#include <iostream>
#include <queue>

using namespace std;

int v[10001];
int res[10001];

int N, e;

void dfs(int start) {
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int p = q.front();
        q.pop();
        if(p == e) return;

        for (int i = p; i > 0; i -= v[p]) {
            if(res[i] != 0) continue;
            res[i] = res[p] + 1;
            q.push(i);
        }
        for (int i = p; i <= N; i += v[p]) {
            if(res[i] != 0) continue;
            res[i] = res[p] + 1;
            q.push(i);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> v[i];

    int start;
    cin >> start >> e;
    res[start] = 1;
    dfs(start);
    cout << res[e] - 1 << "\n";
}