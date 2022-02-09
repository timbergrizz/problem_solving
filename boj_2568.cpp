#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> v;

    int buf1, buf2;

    for (int i = 1; i <= N; ++i) {
        cin >> buf1 >> buf2;
        v.push_back({buf1, buf2});
    }

    sort(v.begin(), v.end());

    vector<int> dp(v.size(), 1);
    vector<int> lis(1, 0);

    int maxVal{0};
    for (int i = 0; i < N; ++i) {
        if (lis.back() < v[i].second) {
            dp[i] = (int) lis.size();
            lis.push_back(v[i].second);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), v[i].second);
            *it = v[i].second, dp[i] = (int) (it - lis.begin());
        }
        maxVal = max(maxVal, dp[i]);
    }

    cout << N - maxVal << "\n";
    vector<bool> visit(v.size(), false);

    for (int i = N - 1; i >= 0; --i) {
        if (dp[i] == maxVal) visit[i] = true, maxVal--;
    }

    for (int i = 0; i < N; ++i) {
        if (!visit[i]) cout <<  v[i].first << "\n";
    }
}