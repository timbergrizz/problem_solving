#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> v(N + 1);
    vector<int> dp(N + 1);

    for(int i=1; i<=N; ++i) {
        cin >> v[i];
        dp[i] = v[i];
    }

    for(int i=2; i<=N; ++i){
        for(int j=i-1; j>0; --j){
            if(v[i] > v[j]) dp[i] = max(dp[i], dp[j] + v[i]);
        }
    }

    sort(dp.begin(), dp.end());
    cout << dp[N] << '\n';
}