#include <iostream>
#include <memory.h>
using namespace std;

int main() {
    int v[17][2];
    int dp[17]{0,};

    memset(v, 0, sizeof(v));
    memset(dp, 0, sizeof(dp));
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) cin >> v[i][0] >> v[i][1];

    dp[0] = 0;
    for (int i = 1; i <= N + 1; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (v[j][0] <= i - j) dp[i] = max(dp[i], dp[j] + v[i][1]);
        }
    }

    cout << dp[N + 1] << "\n";
}