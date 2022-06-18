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
int scc[MAX]{0,};

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

int main() {
    FASTIO
    int N, M;
    cin >> N >> M;

    int c1, c2;
    while (M--) {
        cin >> c1 >> c2;
        c1 = NEG(c1, N), c2 = NEG(c2, N);

        v[OP(c1, N)].push_back(c2);
        v[OP(c2, N)].push_back(c1);

        vt[c1].push_back(OP(c2, N));
        vt[c2].push_back(OP(c1, N));
    }

    si s;

    FOR(i, 2 * N) dfs(i, s);
    int cnt{1};

    memset(visited, 0, sizeof visited);

    while (!s.empty()) {
        int t = s.top();
        s.pop();

        if (!visited[t]) {
            rev_dfs(t, cnt);
            cnt++;
        }
    }

    if (check(N)) {
        cout << 1 << "\n";
        FOR(i, N) cout << (scc[i] > scc[i + N]) << " ";
        cout << "\n";
    } else cout << 0 << "\n";
}