#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int prim(const vector<vector<pii>> &v, const vector<bool> &mw, int N) {
    vector<bool> visited(N + 1);
    priority_queue<pii> pq;
    for (pii it: v[1]) {
        if (mw[1] == mw[it.first]) continue;
        pq.push({-it.second, it.first});
    }
    visited[1] = true;
    int cnt{0}, cost{0};

    while (!pq.empty()) {
        pii cur = pq.top();
        pq.pop();

        if (visited[cur.second]) continue;
        if (cnt == N - 1) break;
        visited[cur.second] = true, cnt++, cost -= cur.first;
//        cout << cur.second << " " << cnt << " " << cost << endl;

        for (pii it: v[cur.second]) pq.push({-it.second, it.first});
    }
    if(cnt != N - 1) return -1;
    return cost;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pii>> v(N + 1);

    vector<bool> mw(N + 1);
    char buf;
    for (int i = 1; i <= N; ++i) {
        cin >> buf;
        (buf == 'M' ? mw[i] = true : mw[i] = false);
    }

    int fir, sec, cost;
    while (M--) {
        cin >> fir >> sec >> cost;
        if(mw[fir] == mw[sec]) continue;
        v[fir].push_back({sec, cost});
        v[sec].push_back({fir, cost});
    }

    cout << prim(v, mw, N) << "\n";
}