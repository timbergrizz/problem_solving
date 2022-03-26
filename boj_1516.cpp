#include <bits/stdc++.h>

#define FOR(i, n) for(int i=1; i <= n ;++i)
using namespace std;

typedef vector<int> vi;

void topology_sort(const vector<vi> &v, vi &inDegree, const vi &time, int n) {
    vector<int> result(n + 1);
    queue<int> q;
    FOR(i, n) {
        if (!inDegree[i]) {
            q.push(i);
            result[i] = time[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i: v[cur]) {
            result[i] = max(time[i] + result[cur], result[i]);
            if(--inDegree[i] == 0) q.push(i);
        }
    }
    FOR(i, n) cout << result[i] << "\n";
}

int main() {
    int N;
    cin >> N;

    vector<vi> v(N + 1);
    vi inDegree(N + 1), time(N + 1);

    FOR(i, N) {
        int temp;
        cin >> time[i] >> temp;
        while (temp != -1) {
            v[temp].push_back(i);
            inDegree[i]++;
            cin >> temp;
        }
    }
    topology_sort(v, inDegree, time, N);
}