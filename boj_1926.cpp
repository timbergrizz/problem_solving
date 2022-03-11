#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;
typedef long long ll;

bool v[501][501]{false,}, res[501][501]{0,};
int dx[5]{0, 1, -1, 0, 0}, dy[5]{0, 0, 0, 1, -1};
int n, m;

void dfs(int y, int x, int &level) {
    if(!v[y][x] || res[y][x]) return;
    res[y][x] = true, ++level;

    FOR(i, 4){
        int py = y + dy[i], px = x + dx[i];
        if(px < 1 || px > m || py < 1 || py > n) continue;
        if(!v[py][px]) continue;
        dfs(py, px, level);
    }
}


int main() {
    cin >> n >> m;

    FOR(i, n) {
        FOR(j, m) cin >> v[i][j];
    }

    int cnt{0}, maxSize{0};
    FOR(i, n) {
        FOR(j, m) {
            if (v[i][j] && !res[i][j]) {
                int lev = 0;
                dfs(i, j, lev);
                cnt++, maxSize = max(maxSize, lev);
            }
        }
    }
    cout << cnt << '\n' << maxSize << '\n';
}