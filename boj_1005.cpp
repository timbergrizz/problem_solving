#include <bits/stdc++.h>

#define INF 1e9
#define FOR(i, N) for(int i=1; i <= N ; ++i)
using namespace std;

typedef vector<int> vi;

int topology_sort(const vector<vi> &v, vi &cost, vi &inDegree, int N, int target) {
    queue<int> q;
    vector<int> result(N + 1);

    FOR(i, N) {
        if (!inDegree[i]) {
            q.push(i);
            result[i] = cost[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i: v[cur]) {
            if (--inDegree[i] == 0) q.push(i);
            result[i] = max(cost[i] + result[cur], result[i]);
        }
    }

    return result[target];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<vi> v(N + 1);
        vi cost(N + 1), inDegree(N + 1);
        int fir, sec;

        FOR(i, N) cin >> cost[i];
        FOR(i, K) {
            cin >> fir >> sec;
            v[fir].push_back(sec), inDegree[sec] += 1;
        }

        int win;
        cin >> win;
        cout << topology_sort(v, cost, inDegree, N, win) << "\n";
    }
}