#include <bits/stdc++.h>
#define FOR(i, N) for(int i=1; i <= N; ++i)
#define INF 40001234
using namespace std;

int V;
int v[401][401]{0,};
int res[401][401]{0,};

int floyd_warshall() {
    FOR(i, V) {
        FOR(j, V) {
            if (i == j) res[i][j] = 0;
            else if (v[i][j] == 0) res[i][j] = INF;
            else res[i][j] = v[i][j];
        }
    }

    FOR(k, V) {
        FOR(i, V) {
            FOR(j, V) res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
        }
    }

    int distMin{INF};
    FOR(j, V){
        FOR(i, V) {
            if(i == j) continue;
            distMin = min(distMin, res[i][j] + res[j][i]);
        }
    }
    return distMin;
}

int main() {
    int E;
    cin >> V >> E;

    int fir, sec, dist;
    while (E--) {
        cin >> fir >> sec >> dist;
        v[fir][sec] = dist;
    }

    int result = floyd_warshall();
    if(result == INF) result = -1;

    cout << result << "\n";
}