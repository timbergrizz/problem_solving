#include <bits/stdc++.h>

using namespace std;

int v[1001]{0,};
int dp[1001][2]{0, };

int main() {
    int N; cin >> N;
    for(int i=1; i <= N; ++i){
        cin >> v[i];
        dp[i][0] = 1;
    }

    int maxIdx{1};
    for(int i=2; i <= N; ++i){
        for(int j=1; j < i; ++j){
            if(v[i] > v[j] && dp[i][0] < dp[j][0] + 1)
                dp[i][0] = dp[j][0] + 1, dp[i][1] = j;
            if(dp[i][0] > dp[maxIdx][0]) maxIdx = i;
        }
    }

    stack<int> s;
    while(maxIdx != 0){
        s.push(v[maxIdx]);
        maxIdx = dp[maxIdx][1];
    }
    cout << s.size() << endl;

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << "\n";
}