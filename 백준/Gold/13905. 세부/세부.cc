#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vpii;
typedef vector<vpii> vvi;

int prim(vvi &tree, int start, int end, int N) {
    priority_queue<piii> pq;
    vector<bool> visited(N + 1);

    pq.push({0, {start, 1e9}});
    int cost = 0;

    while (!pq.empty()) {
        piii t = pq.top();
        pq.pop();

        if(visited[t.second.first]) continue;
        visited[t.second.first] = true;

//        cout << t.second.first << " " << t.second.second << endl;
        if(t.second.first == end) cost = t.second.second;

        for (pii it : tree[t.second.first]) {
//            cout << it.second << endl;
            pq.push({it.first, {it.second, min(t.second.second, it.first)}});
        }
    }
    return cost;
}

int main() {
    int N, M;
    cin >> N >> M;
    int s, e;
    cin >> s >> e;

    vvi v(N + 1);
    int c1, c2, c3;
    FOR(i, M) {
        cin >> c1 >> c2 >> c3;
        v[c1].push_back({c3, c2});
        v[c2].push_back({c3, c1});
    }

    cout << prim(v, s, e, N) << "\n";
}