#include <iostream>
#include <memory.h>
using namespace std;

int dp[1001][1001];

int main(){
    memset(dp, 0, sizeof(dp));
    int N, K; cin >> N >> K;
    for(int i=0; i<= 1000; ++i){
        dp[i][0] = dp[i][i] = 1;
        for(int j=1; j <= i; ++j){
            dp[i][j] = (dp[i - 1] [j - 1] + dp[i - 1][j]) % 10007;
        }
    }
    cout << dp[N][K] << "\n";
}