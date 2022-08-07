#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> si;

bool visited[20202];
vvi v, vt;
vi scc;

void dfs(int x, si &s) {
    visited[x] = true;
    for (int next: v[x]) {
        if (!visited[next]) dfs(next, s);
    }
    s.push(x);
}

//
//void revDfs(int cur, int cnt) {
//    visited[cur] = true, scc[cur] = cnt;
//    for (int i: re_graph[cur]) {
//        if (!visited[i]) revDfs(i, cur);
//    }
//}
void re_dfs(int x, int y) {
    visited[x] = true;
    scc[x] = y;
    for (int next: vt[x]) {
        if (!visited[next]) re_dfs(next, y);
    }
}

int re(int x, int N) {
    return x > N ? x - N : x + N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;

    v.resize(2 * N + 5);
    vt.resize(2 * N + 5);
    scc.resize(2 * N + 5);
    for (int i = 0; i < M; i++) {
        int c1, c2;
        cin >> c1 >> c2;
        if (c1 < 0) c1 = -c1 + N;
        if (c2 < 0) c2 = -c2 + N;
        v[re(c1, N)].push_back(c2);
        v[re(c2, N)].push_back(c1);
        vt[c1].push_back(re(c2, N));
        vt[c2].push_back(re(c1, N));
    }

    si s;
    for (int i = 1; i <= 2 * N + 1; i++) {
        if (!visited[i]) dfs(i, s);
    }
    memset(visited, false, sizeof(visited));
    int idx = 1;
    while (!s.empty()) {
        int t = s.top();
        s.pop();
        if (!visited[t]) re_dfs(t, idx++);
    }
    for (int i = 1; i <= N; i++) {
        if (scc[i] == scc[i + N]) {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
    return 0;
}