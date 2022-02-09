//first platinum! yay!
#include <bits/stdc++.h>

#define NEGINF -1000000001
typedef long long ll;
using namespace std;
ll v[1000001];
ll dp[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        dp[i] = 1;
    }

    vector<ll> lis;

    lis.push_back(NEGINF);
    ll maxVal= 0;

    for (int i = 1; i <= N; ++i) {
        if (lis.back() < v[i]) {
            lis.push_back(v[i]);
            dp[i] = lis.size() - 1;
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
//            cout << it - lis.begin() << endl;
            *it = v[i], dp[i] = (it - lis.begin());
        }
        maxVal = max(maxVal, dp[i]);
    }

    stack<ll> s;

    cout << maxVal << "\n";

    for(int i=N; i > 0; --i){
        if(maxVal == dp[i]) {
            s.push(v[i]);
            maxVal--;
        }
    }

    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}