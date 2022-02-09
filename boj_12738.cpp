#include <bits/stdc++.h>
#define NEGINF -1000000001
using namespace std;

int v[1000001];
int dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N; cin >> N;
    for(int i=1; i <= N; ++i) cin >> v[i];
    vector<int> lis;
    lis.push_back(NEGINF);

    int maxVal{0};
    for(int i=1; i <= N; ++i){
        if(v[i] > lis.back()) {
            dp[i] = lis.size();
            lis.push_back(v[i]);
        }
        else {
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            dp[i] = (int)(it - lis.begin()), *it = v[i];
        }
        maxVal = max(dp[i], maxVal);
    }
    cout << maxVal << "\n";
}