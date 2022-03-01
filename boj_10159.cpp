#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
#define INF 101
using namespace std;

int N;
int v[101][101]{0,};
int res[101];

void floyd_warshall() {
    FOR(k, N) {
        FOR(i, N) {
            FOR(j, N) {
                v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }

    FOR(i, N) {
        FOR(j, N) {
            if (v[i][j] != INF || v[j][i] != INF) continue;
            res[i]++;
        }
    }
    FOR(i, N) cout << res[i] << "\n";
}

int main() {
    int M;
    cin >> N >> M;

    int fir, sec;
    FOR(i, N) {
        FOR(j, N) {
            if (i == j) continue;
            v[i][j] = INF;
        }
    }

    while (M--) {
        cin >> fir >> sec;
        v[fir][sec] = true;
    }

    floyd_warshall();
}