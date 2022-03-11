#include <bits/stdc++.h>

#define FOR(i, N) for(int i=1; i <= N; ++i)
using namespace std;

int v[501][501]{0,};

void floyd_warshall(int n) {
    FOR(k, n) {
        FOR(i, n) {
            FOR(j, n) {
                if (v[i][k] == -1 && v[k][j] == -1) v[i][j] = -1, v[j][i] = 1;
                if (v[i][k] == 1 && v[k][j] == 1) v[i][j] = 1, v[j][i] = -1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, k;
    cin >> N >> k;

    int fir, sec;
    FOR(i, k) {
        cin >> fir >> sec;
        v[fir][sec] = -1, v[sec][fir] = 1;
    }

    floyd_warshall(N);

    int s;
    cin >> s;
    FOR(i, s) {
        cin >> fir >> sec;
        cout << v[fir][sec] << "\n";
    }

}