#include <bits/stdc++.h>

#define NEGINF -1000000001
using namespace std;

int v[100001];
int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=1; i <= N; ++i) cin >> v[i];

    vector<int> lis;
    lis.push_back(0);

    for (int i = 1; i <= N; ++i) {
        if(lis.back() < v[i]) lis.push_back(v[i]);
        else{
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            *it = v[i];
        }
    }
    cout << N - (lis.size() - 1) << "\n";
}