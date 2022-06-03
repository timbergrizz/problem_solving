#include <bits/stdc++.h>

#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define INF 1e9
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<int, int> pll;
typedef vector<pll> vp;
typedef vector<vp> vvp;

ll dijkstra(vvp &v, ll source, ll target, ll N){
    priority_queue<pll> pq;
    vector<ll> cost(N + 1, INF);
    pq.push({0, source});
    cost[source] = 0;

    while(!pq.empty()){
        pll top = pq.top();
        pq.pop();

        for(pll it : v[top.s]) {
            if(cost[it.f] < -top.f + it.s) continue;
            cost[it.f] = -top.f + it.s;
            pq.push({-cost[it.f], it.f});
        }
    }

    return cost[target];
}

int main() {
    FASTIO
    ll N, E; cin >> N >> E;
    ll c1, c2, c3;
    vvp v(N + 1);

    while(E--){
        cin >> c1 >> c2 >> c3;
        v[c1].push_back({c2, c3});
        v[c2].push_back({c1, c3});
    }

    cin >> c1 >> c2;
    ll result{0}, result2{0};

    result += dijkstra(v, 1, c1, N);
    result += dijkstra(v, c1, c2, N);
    result += dijkstra(v, c2, N, N);

    result2 += dijkstra(v, 1, c2, N);
    result2 += dijkstra(v, c2, c1, N);
    result2 += dijkstra(v, c1, N, N);

    result = min(result, result2);

    if(result >= INF) result = -1;
    cout << result;
}