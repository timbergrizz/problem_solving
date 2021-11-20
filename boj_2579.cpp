#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> v(N + 1);
    vector<int> dp(N + 1, 0);

    for(int i=1; i <= N; ++i) cin >> v[i];
    dp[1] = v[1];
    dp[2] = v[1] + v[2];
    dp[3] = max(v[1],v[2]) + v[3];

    for(int i=4; i <= N; ++i){
        dp[i] = max(dp[i-2], dp[i-3] + v[i-1]) + v[i];
    }
    cout << dp[N] << endl;
}