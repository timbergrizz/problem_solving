#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<pll> vpll;
typedef vector<vpll> vpp;

ll dijkstra(vpp &v, int N, int s, int t){
    vl dist(N + 1, 1e9), visited(N + 1);

    priority_queue<pll> pq;
    pq.push({0, s});

    ll cost{0};
    while(!pq.empty()){
        pll top = pq.top();
        pq.pop();

        if(visited[top.s]) continue;
        visited[top.s] = 1;

        for(pll it : v[top.s]){
            if(dist[it.s] < -(it.f + top.f)) continue;
            dist[it.s] = -(it.f + top.f);
            pq.push({-dist[it.s], it.s});
        }
    }
    return dist[t];
}

int main(){
    int N, M; cin >> N >> M;
    vpp v(N + 1);

    int c1, c2, c3;
    while(M--){
        cin >> c1 >> c2 >> c3;
        v[c1].push_back({-c3, c2});
        v[c2].push_back({-c3, c1});
    }

    cin >> c1 >> c2;
    cout << dijkstra(v, N, c1, c2) << "\n";
}