#include <bits/stdc++.h>

#define FOR(i, END) for(int i=1; i <= END; ++i)
#define INF 1e9 + 1
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
typedef long long ll;

ll coin[21], dp[10001];

int main() {
    FASTIO
    int T, N, C, M;
    cin >> T;

    FOR(test, T) {
        memset(coin, 0, sizeof coin);
        memset(dp, 0, sizeof dp);

        cin >> N;
        dp[0] = 1;

        FOR(i, N) cin >> coin[i];

        cin >> M;
        FOR(i, N) {
            FOR(j, M) {
                if (coin[i] <= j) dp[j] += dp[j - coin[i]];
            }
        }
        cout << dp[M] << "\n";
    }
}