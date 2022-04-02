#include <bits/stdc++.h>
#define FOR(i, N) for(int i=0; i < N; ++i)
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

long long prim(const vector<vi> &v, int N){
    priority_queue<pii> pq;
    vi visited(N);
    ll result{0}, cnt{0};

    FOR(i, N){
        pq.push({-v[0][i], i});
    }
    visited[0] = 1;

    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();

        if(visited[cur.second]) continue;
        cnt++, visited[cur.second] = 1, result -= cur.first;
        if(cnt == N - 1) break;

        FOR(i, N) {
            pq.push({-v[cur.second][i], i});
        }
    }

    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    vector<vi> v(N, vi(N));

    for(vi &it : v){
        for(ll &i : it) cin >> i;
    }
    cout << prim(v, N) << "\n";
}