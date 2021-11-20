#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n+1);
    vector<int> dp(n+1, 1);

    for(int i=n; i>=1; --i) cin >> v[i];

    for(int i=2; i<=n; ++i){
        for(int j=i-1; j > 0; --j){
            if(v[i] > v[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    sort(dp.begin(), dp.end());
    cout << dp[n] << "\n";
}