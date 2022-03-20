#include <bits/stdc++.h>

using namespace std;

int dp[51][1001], v[51];

int main() {
    int N, S, M;
    cin >> N >> S >> M;

    dp[0][S] = 1;

    for (int i = 1; i <= N; ++i) cin >> v[i];
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (!dp[i - 1][j]) continue;
            if (j - v[i] >= 0 && j - v[i] <= M) dp[i][j - v[i]] = 1;
            if (j + v[i] >= 0 && j + v[i] <= M) dp[i][j + v[i]] = 1;
        }
    }

    int result{-1};
    for(int i=0; i <= M; ++i){
        if(dp[N][i]) result = i;
    }
    cout << result << "\n";
}