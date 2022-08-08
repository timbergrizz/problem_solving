#include <bits/stdc++.h>

#define FOR(i, N) for(int i=4; i <= N; ++i)
using namespace std;

typedef long long ll;
ll dp[1000]{0, };

int main() {
    int N; cin >> N;
    dp[1] = 1, dp[2] = 0, dp[3] = 1;
    FOR(i, N) dp[i] = min(dp[i - 1] + 1, dp[i - 3] + 1);
    cout << (dp[N] % 2 ? "SK" : "CY");
}