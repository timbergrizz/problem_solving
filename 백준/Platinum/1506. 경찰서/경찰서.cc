#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef stack<int> si;

int idx{1}, N{0}, cur_id{0};
vi id, scc, cost;
vvi v;

int dfs(int cur, si &s) {
    id[cur] = ++cur_id;
    s.push(cur);

    int link = id[cur];

    for (auto next: v[cur]) {
        if (id[next] == 0) link = min(link, dfs(next, s));
        if (scc[next] == -1) link = min(link, id[next]);
    }

    if (link == id[cur]) {
        while (true) {
            int t = s.top();
            s.pop();

            scc[t] = idx;
            if (t == cur) break;
        }
        ++idx;
    }

    return link;
}

void init() {
    id.resize(N + 10);
    scc.resize(N + 10, -1);
    cost.resize(N + 10);
    v.resize(N + 10);
}

int main() {
    FASTIO;
    cin >> N;
    init();

    FOR(i, N) cin >> cost[i];

    string c1;
    FOR(i, N) {
        cin >> c1;
        FOR(j, N) {
            if(c1[j - 1] == '1') v[i].push_back(j);
        }
    }



    si s;
    FOR(i, N){
        if (!id[i]) dfs(i, s);
    }
    long long result{0};

    FOR(i, idx - 1){
        int min = 1e9;
        FOR(j, N) {
            if(scc[j] == i && cost[j] < min) min = cost[j];
        }
        result += min;
    }

    cout << result << "\n";
}