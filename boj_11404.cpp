#include <bits/stdc++.h>

#define INF 12500000
using namespace std;

int N;
int v[126][126]{0,}, res[126][126]{0,};

void floydwarshall() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (i == j) res[i][j] = 0;
            else if (v[i][j] == 0) res[i][j] = INF;
            else res[i][j] = v[i][j];
        }
    }


    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
            }
        }
    }
}

int main() {
    cin >> N;
    int M;
    cin >> M;

    int fir, sec, dist;
    while (M--) {
        cin >> fir >> sec >> dist;
        if (v[fir][sec]) v[fir][sec] = min(dist, v[fir][sec]);
        else v[fir][sec] = dist;
    }

    floydwarshall();
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (res[i][j] == INF) cout << 0 << " ";
            else cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}