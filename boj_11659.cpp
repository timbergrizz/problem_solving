#include <iostream>
#include <vector>

using namespace std;

int v[100001]{0,};
int dp[100001]{0,};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        dp[i] = dp[i - 1] + v[i];
    }
    while (M--) {
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i-1] << "\n";
    }
}