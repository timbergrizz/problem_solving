#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;


int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> v(N);
        for (int &i: v) cin >> i;

        vector<int> lis(1);
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            if (v[i] > lis.back()) {
                dp[i] = (int) lis.size();
                lis.push_back(v[i]);
            }
            else{
                auto it = lower_bound(lis.begin(), lis.end(), v[i]);
                *it = v[i], dp[i] = (int)(it - lis.begin());
            }
        }
        int size{(int)lis.size() - 1};
        cout << size << "\n";

        stack<int> s;
        for(int i=(int)dp.size() - 1; i >= 0; --i) {
            if(size == dp[i]) {
                size--;
                s.push(i + 1);
            }
        }

        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
        cout << "\n";
    }
}