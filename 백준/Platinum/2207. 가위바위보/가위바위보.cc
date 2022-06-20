#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define NEG(i) (i < 0 ? N - i : i)
#define P(i) (i > N ? i - N : i + N)
#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> si;


vvi v, vt;
vi scc;
bool visited[20202];
int N, M;

void dfs(int cur, si &s) {
    visited[cur] = true;
    for (int i: v[cur]) {
        if (!visited[i]) dfs(i, s);
    }

    s.push(cur);
}

void rev_dfs(int x, int y) {
    visited[x] = true;
    scc[x] = y;
    for (int next: vt[x]) {
        if (!visited[next]) rev_dfs(next, y);
    }
}


void SCC() {
    si s;
    FOR(i, 2 * N) {
        if (!visited[i]) dfs(i, s);
    }

    memset(visited, false, sizeof visited);
    int cnt{1};

    while (!s.empty()) {
        int t = s.top();
        s.pop();

        if (!visited[t]) rev_dfs(t, cnt++);
    }
}

bool check() {
    for (int i = 1; i <= N; ++i) {
        if (scc[i] == scc[i + N]) return false;
    }
    return true;
}

void init(){
    v.resize(2 * N + 10);
    vt.resize(2 * N + 10);
    scc.resize(2 * N + 10);
    memset(visited, false, sizeof visited);
}

int main() {
    cin >> M >> N;
    init();

    int c1, c2;
    FOR(i, M) {
        cin >> c1 >> c2;
        c1 = NEG(c1), c2 = NEG(c2);
        v[P(c1)].push_back(c2);
        v[P(c2)].push_back(c1);

        vt[c1].push_back(P(c2));
        vt[c2].push_back(P(c1));
    }

    SCC();
//    for(int i : scc) cout << i << " ";
//    cout << endl;

    cout << (check() ? "^_^" : "OTL");
}