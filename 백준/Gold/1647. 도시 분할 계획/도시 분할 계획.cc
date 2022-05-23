#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int mst(const vector<vector<pii>> &v, int N){
    int cnt{0}, result{0}, maxCost{0};
    priority_queue<pii> pq;
    vector<bool> visited(N + 1);
    pq.push({0, 1});

    while(!pq.empty()){
        int cur = pq.top().second, cost = -pq.top().first;
        pq.pop();

        if(visited[cur]) continue;
        visited[cur] = true;

        result += cost, cnt++, maxCost = max(cost, maxCost);
        if(cnt == N) break;

        for(pii p : v[cur]) pq.push({-p.second, p.first});
    }
    return result - maxCost;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; cin >> N >> M;
    vector<vector<pii>> v(N + 1);

    int fir, sec, cost;
    while(M--){
        cin >> fir >> sec >> cost;
        v[fir].push_back({sec, cost});
        v[sec].push_back({fir, cost});
    }

    cout << mst(v, N) << "\n";
}