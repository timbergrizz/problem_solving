#include <bits/stdc++.h>

#define FOR(i, k, N) for(int i=k; i <= N; ++i)
#define INF 1e9
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef vector<int> vl;
typedef vector<vl> vvl;

int min_calc(vvl &dp, vl &p, int N) {
    vvl process(N + 1, vl(N + 1));
    FOR(i, 1, N) {
        FOR(j, 1, N - i) {
            int fir = j, sec = j + i;
            FOR(k, fir, sec - 1) {
//                cout << fir << " " << k << " " << sec << " " << dp[fir][k] << " " << dp[k+1][sec] << endl;
//                cout << dp[fir][k] + dp[k + 1][sec] + p[fir - 1] * p[k] * p[sec] << "\n";
                if (dp[fir][sec] < dp[fir][k] + dp[k + 1][sec] + p[fir - 1] * p[k] * p[sec]) continue;
                dp[fir][sec] = dp[fir][k] + dp[k + 1][sec] + p[fir - 1] * p[k] * p[sec];
                process[fir][sec] = k;
            }
//            cout << fir << " " << sec << " " << dp[fir][sec] << endl;
        }
    }
//    FOR(i, 1, N){
//        FOR(j, i, N) cout << process[i][j] << " ";
//        cout << endl;
//    }
    return dp[1][N];
}

int main() {
    FASTIO
    int N;
    cin >> N;
    vl p(N + 1);
    vvl dp(N + 1, vl(N + 1, INF));

    int c1, c2;
    FOR(i, 0, N - 1) {
        cin >> c1 >> c2;
        p[i] = c1;
        dp[i][i] = 0;
    }
    dp[N][N] = 0, p[N] = c2;

    cout << min_calc(dp, p, N);
}