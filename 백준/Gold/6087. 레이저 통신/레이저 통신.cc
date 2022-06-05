#include <bits/stdc++.h>

#define f first
#define s second
#define FOR(i, N) for(ll i=0; i < N; ++i)
#define FASTIO ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;

struct pos {
    ll y, x, dir, c;
};

typedef vector<pos> vp;
typedef vector<string> vs;

ll dx[4]{1, -1, 0, 0}, dy[4]{0, 0, 1, -1};

ll dijkstra(vs &v, vp &src, ll W, ll H) {
    queue<pos> pq;

    vvl cost(H + 1, vl(W + 1, 1e9));
    cost[src[0].y][src[0].x] = 0;
    for(int k=0; k< 4; ++k) pq.push({src[0].y, src[0].x, k, 0});

    while (!pq.empty()) {
        pos top = pq.front();
        pq.pop();

        FOR(i, 4) {
            ll curCost = top.c + (i != top.dir ? 1 : 0);
            pos next = {top.y + dy[i], top.x + dx[i], i, curCost};

            if (next.x < 0 || next.x >= W || next.y < 0 || next.y >= H) continue;
            if (v[next.y][next.x] == '*') continue;

//            cout << curCost << " " << next.dir << " " << next.y << " " << next.x << endl;
            if (cost[next.y][next.x] < curCost) continue;

            cost[next.y][next.x] = curCost;
            pq.push(next);
        }
    }

    return cost[src[1].y][src[1].x];
}

int main() {
    FASTIO
    ll W, H;
    cin >> W >> H;

    vs v(H);


    vp src;
    FOR(i, H) {
        cin >> v[i];
        FOR(j, W) {
            if (v[i][j] == 'C') src.push_back({i, j, -1, 0});
        }
    }

    cout << dijkstra(v, src, W, H) << "\n";
}