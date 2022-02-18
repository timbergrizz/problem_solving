#include <bits/stdc++.h>

using namespace std;

long long v[101][101]{0, }, dp[101][101]{0, };

int main() {
    int N; cin >> N;

    for(int i=1; i <= N; ++i){
        for(int j=1; j <= N ; ++j) cin >> v[i][j];
    }
    dp[1][1] = 1;

    for(int i=1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if(i == N && j == N) break;

            if (i + v[i][j] <= N) dp[i + v[i][j]][j] += dp[i][j];
            if (j + v[i][j] <= N) dp[i][j + v[i][j]] += dp[i][j];
        }
    }

    cout << dp[N][N] << "\n";
}