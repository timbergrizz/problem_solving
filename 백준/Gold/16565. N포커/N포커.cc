#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MOD 10007
#define FOR(i, init, n) for(int i=init; i < n; ++i)

using namespace std;
typedef long long ll;

ll dp[53][53]{0,};


int main() {
    FASTIO
    int n;
    cin >> n;

    FOR(i, 0, 53) {
        dp[i][0] = dp[i][i] = 1;
        FOR(j, 1, i) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
    }

    ll result{0};

    for (ll i = 1; i <= 13 && n - 4 * i >= 0; ++i) {
        ll temp = 4 * i;
        if (i % 2) result = (result + dp[52 - temp][n - temp] * dp[13][i] % MOD) % MOD;
        else result = (result - dp[52 - temp][n - temp] * dp[13][i] % MOD + MOD) % MOD;
    }

    cout << (result % MOD) << endl;
}

