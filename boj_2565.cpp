#include <bits/stdc++.h>

#define loop(i, n) for(int i=0; i < n ; ++i)
using namespace std;
typedef pair<int, int> pii;

vector<pii> v;
int dp[501]{0,};
int N;

int dp_calc() {
    int res = 0;
    loop(i, v.size()) {
        loop(j, i) {
            if (v[j].second < v[i].second) dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(dp[i], res);
    }

    return N - res;
}


int main() {
    cin >> N;
    int fir, sec;
    loop(i, 501) dp[i] = 1;

    loop(i, N) {
        cin >> fir >> sec;
        v.push_back({fir, sec});
    }

    sort(v.begin(), v.end());
    cout << dp_calc() << endl;
}