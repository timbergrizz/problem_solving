#include <iostream>

using namespace std;

long long dp[30][30]{1};

int main(){
    for(int i=1; i < 30; ++i){
        dp[i][0] = dp[i][i] = 1;
        for(int j=1; j < i; ++j) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
    }

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
}