#include <iostream>
#include <memory.h>
using namespace std;

int dp[1025][1025];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(dp, 0, sizeof(dp));

    int N, M;
    cin >> N >> M;
    int buf{0};
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> buf;
            dp[i][j] = dp[i][j - 1] + buf;
        }
    }

    int x1, x2, y1, y2, res;
    while (M--) {
        cin >> y1>> x1 >> y2 >> x2;
        res = 0;
        for(int i = y1; i <= y2; ++i) res += dp[i][x2] - dp[i][x1-1];
        cout << res << "\n";
    }
}