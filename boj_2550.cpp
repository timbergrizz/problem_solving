#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> switchNum(N );
    vector<int> idxToSwitch(N );
    vector<int> dp(N);
    int buf;

    for (int i = 0; i < N; ++i) {
        cin >> buf;
        switchNum[buf - 1].first = i;
        idxToSwitch[i] = buf;
    }

    for (int i = 0; i < N; ++i) {
        cin >> buf;
        switchNum[buf - 1].second = i;
    }

    sort(switchNum.begin(), switchNum.end());

    vector<int> lis(1, -1);

    for (int i = 0; i < N; ++i) {
        if (lis.back() < switchNum[i].second) {
            dp[i] = (int) lis.size();
            lis.push_back(switchNum[i].second);
        } else {
            auto it = lower_bound(lis.begin(), lis.end(), switchNum[i].second);
            *it = switchNum[i].second;
            dp[i] = (int) (it - lis.begin());
        }
    }

    int lisSize = (int)(lis.size() - 1);
    cout << lisSize << "\n";
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=N-1; i >= 0 || lisSize; --i){
        if(dp[i] == lisSize) {
            pq.push(idxToSwitch[i]);
            lisSize--;
        }
    }
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}