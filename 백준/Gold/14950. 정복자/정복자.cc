#include <bits/stdc++.h>
#define f first
#define s second
#define FOR(i, N) for(int i=1; i<=N ; ++i)
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

vector<pii> v[10001];
bool visited[10001];

ll prim(int N, int T) {
    priority_queue<pii> pq;
    for(pii i : v[1]) pq.push({-i.s, i.f});
    visited[1] = true;

    ll curT{0}, sizePQ, totalCost{0}, nodeNum{0};

    while (!pq.empty()) {
        sizePQ = (int)pq.size();
        while(sizePQ--){
            pii cur = pq.top();
            pq.pop();

            if(visited[cur.s]) continue;
            visited[cur.s] = true, totalCost += -cur.f + (T * nodeNum++);

            for(pii i : v[cur.s]) {
                if(visited[i.f]) continue;
                pq.push({-i.s, i.f});
            }
        }

    }

    return totalCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M, T;
    cin >> N >> M >> T;

    ll c1, c2, c3;
    FOR(i, M){
        cin >> c1 >> c2 >> c3;
        v[c1].push_back({c2, c3});
        v[c2].push_back({c1, c3});
    }

    cout << prim(N, T) << '\n';
}