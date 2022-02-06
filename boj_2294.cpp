#include <bits/stdc++.h>

#define FOR(x, n) for(int x = 0; x < n; ++x)

using namespace std;

int v[110], dp[10010];

int main() {
    memset(v, 0, sizeof v);
    for(int i=0; i < 10001; ++i) dp[i] = 100000;

    int n, k;
    cin >> n >> k;

    FOR(i, n) {
        cin >> v[i];
        if(v[i] <= k) dp[v[i]] = 1;
    }

    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n ; ++j) {
            if(i - v[j] < 0) continue;
            if (dp[i - v[j]] + 1 < dp[i]) dp[i] = dp[i - v[j]] + 1;
        }
    }

    if (dp[k] == 100000) cout << -1 << "\n";
    else cout << dp[k] << "\n";
}