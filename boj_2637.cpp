#include <bits/stdc++.h>

using namespace std;

typedef pair<int, long long> pii;
typedef vector<long long> vi;

void topology_sort(const vector<vector<pii>> &v, vi &inDegree, vector<vi> &dp, int N) {
    queue<int> q;
    for(int i=1; i <= N; ++i){
        if(inDegree[i] == 0)  {
            q.push(i);
            dp[i][i] = 1;
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(pii it : v[cur]) {
            for(int i=1; i <= N; ++i) dp[it.first][i] += (it.second * dp[cur][i]);
            if(--inDegree[it.first] == 0) q.push(it.first);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pii>> v(N + 1);
    vi inDegree(N + 1);
    vector<vi> dp(N + 1, vi(N + 1));


    int fir, sec, cost;
    while (M--) {
        cin >> fir >> sec >> cost;
        v[sec].push_back({fir, cost});
        inDegree[fir]++;
    }

    topology_sort(v, inDegree, dp, N);
    for(int i=1; i <= N; ++i) if(dp[N][i] != 0) cout << i << ' ' << dp[N][i] << "\n";
}