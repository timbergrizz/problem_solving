#include <bits/stdc++.h>
#define INF 100001
using namespace std;

int v[21][2], dp[21][INF];

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    memset(v, 0, sizeof(v));
    memset(dp, 0, sizeof(dp));

    int N, C; cin >> C >> N;
    for(int i=1; i<= N; ++i) cin >> v[i][0] >> v[i][1];

    for(int i=1; i < INF; ++i){
        for(int j=1; j<=N; ++j){
            if(i - v[j][0] < 0) dp[j][i] = 0;
            else dp[j][i] = max(dp[0][i-1], dp[0][i - v[j][0]] + v[j][1]);
            dp[0][i] = max(dp[0][i], dp[j][i]);
        }
    }

    for(int i=0; i< INF; ++i){
        if(dp[0][i] >= C) {
            cout << i << "\n";
            break;
        }
    }
}