#include <bits/stdc++.h>

#define FOR(i, END) for(int i=1; i <= END; ++i)
#define INF 1e9 + 1
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;

ll dp[101][10101]{0,}, cost[101]{0,}, mem[101]{0,};

int main() {
    FASTIO
    ll N, M, sum{0};
    cin >> N >> M;

    FOR(i, N) cin >> mem[i];
    FOR(i, N) {
        cin >> cost[i];
        sum += cost[i];
    }

    ll minCost{101010};

    FOR(i, N) {
        for (ll j = 0; j <= sum; ++j) {
            if (cost[i] > j) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + mem[i]);

            if (dp[i][j] >= M) minCost = min(minCost, j);
        }
    }

    cout << minCost;
}