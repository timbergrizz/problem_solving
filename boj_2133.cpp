#include <iostream>

using namespace std;

int dp[30]{1, 0};

int main() {
    int N;
    cin >> N;
    for (int i = 2; i <= N; i += 2) {
        dp[i] = dp[i - 2] * 3;
        for(int j=0; j < i - 2; j += 2){
            dp[i] += dp[j] * 2;
        }
    }
    cout << dp[N] << "\n";
}