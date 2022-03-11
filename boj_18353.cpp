#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N), dp(N);
    for (int &i: v) cin >> i;

    int maxVal{0};
    for(int i=0; i < N; ++i){
        for(int j=0; j < i; ++j){
            if(v[j] > v[i] && dp[j] > dp[i]) dp[i] = dp[j];
        }
        dp[i] += 1;
        maxVal = max(dp[i], maxVal);
    }
    cout << N - maxVal << "\n";
}