#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

int v[101][2];
int dp[101][100001];

int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; ++i) cin >> v[i][0] >> v[i][1];

    // 물건의 개수에 대해 중량을 모두 기록
    // 중량에 따라 들어갈 수 있는 물건을 기록

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            // i번째 물건을 넣지 않는 경우는 전의 값을 가져다 쓴다
            dp[i][j] = dp[i - 1][j];
            // i번째 물건을 넣는 경우는 현재 무게 + 넣고자 하는 무게의 v값을 더함
            if (j - v[i][0] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i][0]] + v[i][1]);
        }
    }
    cout << dp[N][K] << endl;
}