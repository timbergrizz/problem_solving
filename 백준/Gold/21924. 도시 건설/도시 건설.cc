#include <bits/stdc++.h>
#define f first
#define s second
#define FOR(i, N) for(int i=1; i<=N; ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;

ll prim(const vvpii &G, int N){
    priority_queue<pii> pq;
    vector<bool> visited(N + 1);
    ll result{0}, count{0};
    pq.push({0, 1});

    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();

        if(visited[cur.s]) continue;
        visited[cur.s] = true, result -= cur.first, count++;

        for(pii it : G[cur.s]){
            if(visited[it.first]) continue;
            pq.push({-it.second, it.first});
        }
    }

    return (count == N ? result : -1);
}

int main(){
    int N, M; cin >> N >> M;
    int c1, c2, c3;
    vvpii v(N + 1);

    ll totalCost{0};
    FOR(i, M){
        cin >> c1 >> c2 >> c3;
        v[c1].push_back({c2, c3});
        v[c2].push_back({c1, c3});
        totalCost += c3;
    }

    ll reducedCost = prim(v, N);

    if(reducedCost == -1) totalCost = -1;
    else totalCost -= reducedCost;
    
    cout << totalCost <<"\n";
}