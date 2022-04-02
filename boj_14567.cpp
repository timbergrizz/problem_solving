#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

void topology_sort(const vector<vi> &v, vi &inDegree, vi &cnt, int N) {
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (inDegree[i] == 0) q.push(i);
        cnt[i] = 1;
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i: v[cur]) {
            if (--inDegree[i] == 0) {
                cnt[i] = max(cnt[i], cnt[cur] + 1);
                q.push(i);
            }
        }
    }
}


int main() {
    int N, M;
    cin >> N >> M;

    vector<vi> v(N + 1);
    vi inDegree(N + 1);
    vi cnt(N + 1);

    int fir, sec;
    while (M--) {
        cin >> fir >> sec;
        v[fir].push_back(sec);
        inDegree[sec]++;
    }

    topology_sort(v, inDegree, cnt, N);
    for (int i = 1; i <= N; ++i) cout << cnt[i] << " ";
    cout << "\n";
}