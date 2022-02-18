#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int &i: A) cin >> i;

    vector<int> lis(1);
    vector<pair<int, int>> dp(N, {0, 0});

    for (int i = 0; i < N; ++i) {
        if (lis.back() < A[i]) {
            dp[i].first = (int) lis.size();
            lis.push_back(A[i]);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), A[i]);
            *it = A[i], dp[i].first = (int) (it - lis.begin());
        }
    }

    lis = vector<int>(1);
    for (int i = N - 1; i >= 0; --i) {
        if (lis.back() < A[i]) {
            dp[i].second = (int) lis.size();
            lis.push_back(A[i]);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), A[i]);
            *it = A[i], dp[i].second = (int) (it - lis.begin());
        }
    }

    int result{0};
    for (int i = 0; i < N; ++i) {
//        cout << dp[i].first << " " << dp[i].second << endl;
        result = max(dp[i].first + dp[i].second, result);
    }

    cout << result - 1 << "\n";
}