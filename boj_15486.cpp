#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; cin >> N;
    vector<vector<int>> v(N, vector<int>(2));
    vector<int> dp(N + 1);

    for (int i=0; i < N; ++i) cin >> v[i][0] >> v[i][1];

    int result{0};

    for (int i = 0; i < N; ++i) {
//        cout << v[i][0] << " " << v[i][1] << "\n";
        int dayOn = i + v[i][0];
        dp[i + 1] = max(dp[i], dp[i + 1]);
        if(dayOn > N) continue;
//        cout << i << " " << dayOn << endl;
        dp[dayOn] = max(dp[dayOn], dp[i] + v[i][1]);
    }

    cout << dp[N] << endl;
}