#include <bits/stdc++.h>

using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int &i: v) cin >> i;
    vector<int> dp(N, 1);

    int maxVal{1};
    for (int i = 1; i < N; ++i) {
        if (v[i - 1] <= v[i]) dp[i] = dp[i - 1] + 1;
        maxVal = max(maxVal, dp[i]);
    }

    dp = vector<int>(N, 1);
    for (int i = N - 2; i >= 0; --i) {
        if (v[i + 1] <= v[i]) dp[i] = dp[i + 1] + 1;
        maxVal = max(maxVal, dp[i]);
    }
    cout << maxVal;
}