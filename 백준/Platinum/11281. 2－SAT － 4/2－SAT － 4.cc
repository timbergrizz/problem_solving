#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i<= N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define OP(i, N) (i > N ? i - N : i + N)
#define NEG(i, N) (i < 0 ? N - i : i)
#define MAX 202020

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> si;
typedef pair<int, int> pii;
int n, m;

bool visited[MAX]{false,};
vi v[MAX], vt[MAX];
int scc[MAX]{0, };

void dfs(int cur, si &s) {
    if (visited[cur]) return;
    visited[cur] = true;

    for (int i: v[cur]) {
        if (!visited[i]) dfs(i, s);
    }

    s.push(cur);
}


void rev_dfs(int cur, int y) {
    if (visited[cur]) return;

    visited[cur] = true, scc[cur] = y;

    for (int next: vt[cur]) {
        if (!visited[next]) rev_dfs(next, y);
    }
}

int check(int N) {
    FOR(i, N) {
        if (scc[i] == scc[i + N]) return 0;
    }
    return 1;
}


int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        if (x < 0) x = n - x;
        if (y < 0) y = n - y;

        vt[x].push_back(OP(y, n));
        vt[y].push_back(OP(x, n));
        v[OP(y, n)].push_back(x);
        v[OP(x, n)].push_back(y);
    }
    stack<int> s;
    for (int i = 1; i <= 2 * n; i++) {
        if (!visited[i]) dfs(i, s);
    }
    int r = 0;
    memset(visited, 0, sizeof(visited));

    while (!s.empty()) {
        int t = s.top(); s.pop();
        if (visited[t]) continue;
        rev_dfs(t, r++);
    }

    int f = 1;
    for (int i = 1; i <= n; i++) {
        if (scc[i] == scc[n + i]) f = 0;
    }
    cout << f << "\n";
    if (f == 1) {
        for (int i = 1; i <= n; i++) cout << (scc[i] > scc[n + i]) << " ";
    }
}
