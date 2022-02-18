#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> j(N);
    for (int i = 0; i < N; ++i) cin >> j[i].first >> j[i].second;

    vector<int> c(K);
    for(int i=0; i < K; ++i) cin >> c[i];

    sort(c.begin(), c.end());
    sort(j.begin(), j.end());

    long long result{0}, idx{0};

    priority_queue<int> pq;

    for(int i=0; i < K; ++i){
        while(idx < N && j[idx].first <= c[i]) pq.push(j[idx++].second);
        if(!pq.empty()){
            result += pq.top();
            pq.pop();
        }
    }
    cout << result << "\n";
}