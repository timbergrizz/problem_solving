#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n+1);
    vector<int> dp(n+1);

    for(int i=1; i<=n; ++i){
        cin >> v[i];
        dp[i] = v[i];
    }

    for(int i=1; i<=n; ++i){
        dp[i] = max(dp[i-1] + v[i], v[i]);
    }

    sort(dp.begin() + 1, dp.end());
    cout << dp[n] << endl;
}