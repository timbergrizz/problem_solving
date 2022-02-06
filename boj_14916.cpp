#include <bits/stdc++.h>

using namespace std;

int v[2]{5, 2};
int dp[100001]{0, };
int main() {
    for(int i=0; i < 100001; ++i) dp[i] = -1;
    dp[2] = dp[5] = 1, dp[4] = 2;
    int N; cin >> N;
    for(int i=6; i <= N; ++i){
        for(int j : v){
            if(i - j < 0) continue;
            if(dp[i - j] == -1) continue;

            if(dp[i] == -1) dp[i] = dp[i - j] + 1;
            else dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    cout << dp[N] << endl;
}