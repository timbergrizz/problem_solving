#include <bits/stdc++.h>

#define INF 100001
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> si;

void dfs(int cur, vvi &v, si &s, vi &visited, int par) {
    if (visited[cur]) return;
    visited[cur] = true;

    for (int i: v[cur]) dfs(i, v, s, visited, par);
    s.push(cur);
}

void dfs_reverse(int cur, vvi &v, vi &visited, const int &par, vvi &scc, int cnt, vi &component) {
    if (visited[cur]) return;
    visited[cur] = true, component[cur] = cnt;
    scc[cnt].push_back(cur);

    for (int i: v[cur]) {
        dfs_reverse(i, v, visited, par, scc, cnt, component);
    }
}

int main() {
    FASTIO
    int T;
    cin >> T;

    int N, M, c1, c2;
    vi indegree(INF), visited(INF);
    vvi v(INF), vt(INF);
    si s;

    while (T--) {
        while (!s.empty()) s.pop();
        for (int i = 0; i < INF; ++i) {
            indegree[i] = 0, visited[i] = 0;
            v[i].clear();
            vt[i].clear();
        }

        cin >> N >> M;
        while (M--) {
            cin >> c1 >> c2;
            v[c1].push_back(c2);
            indegree[c2] += 1;
            vt[c2].push_back(c1);
        }

        for (int i = 1; i <= N; ++i) dfs(i, v, s, visited, i);
        for (int &i: visited) i = 0;

        vvi scc;
        int cnt{0};
        vi component(N + 1);
        while (!s.empty()) {
            int t = s.top();
            s.pop();

            if (visited[t]) continue;

            scc.push_back(vi());
            dfs_reverse(t, vt, visited, t, scc, cnt, component);
            cnt++;
        }

        for (auto &it: scc) {
            for (int cur: it) {
                for (int next: v[cur])
                    if (component[next] == component[cur])indegree[next]--;
            }
        }

        int result{cnt};

        for (auto &it: scc) {
            for (int cur: it) {
                if (indegree[cur] != 0) {
                    result -= 1;
                    break;
                }
            }
        }

        cout << result << "\n";
    }
}