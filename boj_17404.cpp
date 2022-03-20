#include <bits/stdc++.h>

#define INF 10000001
#define FOR(i, n) for(int i=1; i <= n; ++i)
using namespace std;

int v[1001][3]{0,};
int dp[1001][3]{0,};

void getCost(int N) {
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
        dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + v[i][2];
    }
}

int main() {
    int N;
    cin >> N;
    FOR(i, N) FOR(j, 3) cin >> v[i][j - 1];
    FOR(i, 3) dp[1][i - 1] = v[1][i - 1];

    // 시작점을 기준으로 경우의 수를 나누어 연산하면 된다.
    // 이후 마지막 결과값에서 시작점을 제외하면 된다.

    int result{INF};
    dp[1][0] = v[1][0], dp[1][1] = dp[1][2] = INF;
    getCost(N);
    result = min(result, min(dp[N][1], dp[N][2]));

    dp[1][1] = v[1][1], dp[1][0] = dp[1][2] = INF;
    getCost(N);
    result = min(result, min(dp[N][0], dp[N][2]));

    dp[1][2] = v[1][2], dp[1][1] = dp[1][0] = INF;
    getCost(N);
    result = min(result, min(dp[N][1], dp[N][0]));

    cout << result << "\n";
}