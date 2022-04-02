#include <bits/stdc++.h>
#define MAX 200001
using namespace std;

typedef int ll;
typedef pair<ll, ll> pii;

ll mst(const vector<vector<pii>> &v, vector<bool> visited, int m) {
    ll cnt{0}, result{0};
    priority_queue<pii> pq;
    for(pii it : v[0]) pq.push({-it.second, it.first});
    visited[0] = true;

    while (!pq.empty()) {
        ll cur = pq.top().second, cost = -pq.top().first;
        pq.pop();

        if (visited[cur]) continue;
        visited[cur] = true, cnt++, result += cost;
        if(cnt == m) break;

        for (pii it: v[cur]) pq.push({-it.second, it.first});
    }
    return result;
}

int main() {
    vector<vector<pii>> v(MAX);
    vector<bool> visited(MAX);

    while(true){
        int m, n;
        cin >> m >> n;
        if(m == n && m == 0) break;

        for(int i=0; i < MAX; ++i){
            v[i].clear();
            visited[i] = false;
        }

        ll fir, sec, cost, totalCost{0};
        while (n--){
            cin >> fir >> sec >> cost;
            v[fir].push_back({sec, cost});
            v[sec].push_back({fir, cost});
            totalCost += cost;
        }

        cout << totalCost - mst(v, visited, m) << "\n";
    }
    //억까 씨발
}