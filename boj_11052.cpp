#include <iostream>
#include <algorithm>
using namespace std;

int v[10001]{0};
int dp[10001];

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) cin >> v[i];
    dp[1] = v[1];
    for (int i = 2; i <= N; ++i) {
        dp[i] = v[i];
        for (int j{i}; j >= i / 2; --j) dp[i] = max(dp[i], dp[i - j] + dp[j]);
    }
    cout << dp[N] << endl;
}